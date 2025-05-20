#include "model_plane.h"    // 함수 선언
#include "utils.h"          // 차영상 계산 함수
#include <opencv2/opencv.hpp>
using namespace cv;

// 1차 모델링 및 밝기 보정, Otsu 이진화까지 수행하는 통합 함수
// mode: 1 = 배경 모델링만, 2 = 모델링 + 차영상, 3 = + Otsu 이진화
void run_model_plane(const std::string& img_path, int mode) {
    // 1. 영상 불러오기
    Mat img = imread(img_path, IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << "Image load failed: " << img_path << std::endl;
        return;
    }

    // 2. 최소자승법을 위한 A행렬(x, y, 1), B벡터(intensity) 구성
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

    // 3. 계수 X 
    Mat X = (A.t() * A).inv() * (A.t() * B);
    Mat B_hat = A * X;

    // 4. 모델링된 배경 영상 생성
    Mat background(rows, cols, CV_8UC1);
    idx = 0;
    for (int y = 0; y < rows; ++y)
        for (int x = 0; x < cols; ++x, ++idx)
            background.at<uchar>(y, x) = saturate_cast<uchar>(B_hat.at<double>(idx, 0));

    // 5. 결과 저장 및 출력
    imwrite("result_plane_background.png", background);
    imshow("Original", img);
    imshow("Estimated Background (1st-order)", background);

    // 6. mode 2 이상인 경우 조명 보정 (차영상)
    if (mode >= 2) {
        Mat corrected = compute_difference_inverse(img, background);
        imwrite("result_plane_corrected.png", corrected);
        imshow("Corrected Image (1st-order)", corrected);

        // 7. mode 3일 경우 Otsu 이진화까지 수행
        if (mode == 3) {
            Mat binary;
            threshold(corrected, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
            imwrite("result_plane_otsu.png", binary);
            imshow("Otsu Result (1st-order)", binary);
        }
    }

    waitKey(0);
}
