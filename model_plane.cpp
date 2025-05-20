#include "model_plane.h"    // �Լ� ����
#include "utils.h"          // ������ ��� �Լ�
#include <opencv2/opencv.hpp>
using namespace cv;

// 1�� �𵨸� �� ��� ����, Otsu ����ȭ���� �����ϴ� ���� �Լ�
// mode: 1 = ��� �𵨸���, 2 = �𵨸� + ������, 3 = + Otsu ����ȭ
void run_model_plane(const std::string& img_path, int mode) {
    // 1. ���� �ҷ�����
    Mat img = imread(img_path, IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << "Image load failed: " << img_path << std::endl;
        return;
    }

    // 2. �ּ��ڽ¹��� ���� A���(x, y, 1), B����(intensity) ����
    int rows = img.rows;
    int cols = img.cols;
    int size = rows * cols;

    Mat A(size, 3, CV_64FC1);
    Mat B(size, 1, CV_64FC1);
    int idx = 0;
    for (int y = 0; y < rows; ++y)
        for (int x = 0; x < cols; ++x, ++idx) {
            A.at<double>(idx, 0) = x;
            A.at<double>(idx, 1) = y;
            A.at<double>(idx, 2) = 1.0;
            B.at<double>(idx, 0) = (double)img.at<uchar>(y, x);
        }

    // 3. ��� X 
    Mat X = (A.t() * A).inv() * (A.t() * B);
    Mat B_hat = A * X;

    // 4. �𵨸��� ��� ���� ����
    Mat background(rows, cols, CV_8UC1);
    idx = 0;
    for (int y = 0; y < rows; ++y)
        for (int x = 0; x < cols; ++x, ++idx)
            background.at<uchar>(y, x) = saturate_cast<uchar>(B_hat.at<double>(idx, 0));

    // 5. ��� ���� �� ���
    imwrite("result_plane_background.png", background);
    imshow("Original", img);
    imshow("Estimated Background (1st-order)", background);

    // 6. mode 2 �̻��� ��� ���� ���� (������)
    if (mode >= 2) {
        Mat corrected = compute_difference_inverse(img, background);
        imwrite("result_plane_corrected.png", corrected);
        imshow("Corrected Image (1st-order)", corrected);

        // 7. mode 3�� ��� Otsu ����ȭ���� ����
        if (mode == 3) {
            Mat binary;
            threshold(corrected, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
            imwrite("result_plane_otsu.png", binary);
            imshow("Otsu Result (1st-order)", binary);
        }
    }

    waitKey(0);
}
