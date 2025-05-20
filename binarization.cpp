#include "binarization.h"
#include "model_plane.h"
#include "utils.h"
#include <opencv2/opencv.hpp>
using namespace cv;

// 1�� �𵨸� ��� ���� ���� + Otsu ����ȭ ���� �Լ� (3.3)
void run_binarization(const std::string& img_path) {
    // 1. ���� �ҷ�����
    Mat img = imread(img_path, IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << "Failed to load image: " << img_path << std::endl;
        return;
    }

    // 2. 1�� �� A ���, B ���� ����
    int rows = img.rows;
    int cols = img.cols;
    int size = rows * cols;

    Mat A(size, 3, CV_64FC1);
    Mat B(size, 1, CV_64FC1);
    int idx = 0;
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x, ++idx) {
            A.at<double>(idx, 0) = x;
            A.at<double>(idx, 1) = y;
            A.at<double>(idx, 2) = 1.0;
            B.at<double>(idx, 0) = static_cast<double>(img.at<uchar>(y, x));
        }
    }

    // 3. �ּ��ڽ¹����� ��� �𵨸�
    Mat X = (A.t() * A).inv() * (A.t() * B);
    Mat background = A * X;

    // 4. ��� ���� ����
    Mat bg_img(rows, cols, CV_8UC1);
    idx = 0;
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x, ++idx) {
            double val = background.at<double>(idx, 0);
            bg_img.at<uchar>(y, x) = saturate_cast<uchar>(val);
        }
    }

    // 5. ���� ������ ���� ������ ���
    Mat corrected = compute_difference_inverse(img, bg_img);

    // 6. Otsu �˰����� �̿��� ����ȭ
    Mat binary;
    threshold(corrected, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // 7. ��� ��� �� ����
    imshow("Otsu Binarization", binary);
    imwrite("result_plane_otsu.png", binary);
    waitKey(0);
}
