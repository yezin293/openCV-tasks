#include "model_quad.h"   // 함수 선언부
#include "utils.h"        // 조명 보정용 차영상 함수
#include <opencv2/opencv.hpp>
using namespace cv;

// 영상 밝기값을 1차 또는 2차 함수로 모델링하여 배경 밝기 근사
Mat estimate_background(const Mat& img, bool use_quadratic) {
    int rows = img.rows;
    int cols = img.cols;
    int size = rows * cols;

    Mat A, B(size, 1, CV_64FC1);
    // A 행렬 구성: 1차(3개 항), 2차(6개 항)
    if (use_quadratic) {
        A = Mat(size, 6, CV_64FC1); // [x², y², xy, x, y, 1]
    }
    else {
        A = Mat(size, 3, CV_64FC1); // [x, y, 1]
    }

    // A, B 채우기
    int idx = 0;
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x, ++idx) {
            if (use_quadratic) {
                A.at<double>(idx, 0) = x * x;
                A.at<double>(idx, 1) = y * y;
                A.at<double>(idx, 2) = x * y;
                A.at<double>(idx, 3) = x;
                A.at<double>(idx, 4) = y;
                A.at<double>(idx, 5) = 1.0;
            }
            else {
                A.at<double>(idx, 0) = x;
                A.at<double>(idx, 1) = y;
                A.at<double>(idx, 2) = 1.0;
            }
            B.at<double>(idx, 0) = static_cast<double>(img.at<uchar>(y, x));
        }
    }

    // 최소자승법: X = (A?A)^(-1) A?B
    Mat X = (A.t() * A).inv() * (A.t() * B);
    Mat B_hat = A * X;

    // 배경 밝기 영상 생성
    Mat background(img.rows, img.cols, CV_8UC1);
    idx = 0;
    for (int y = 0; y < img.rows; ++y) {
        for (int x = 0; x < img.cols; ++x, ++idx) {
            double val = B_hat.at<double>(idx, 0);
            background.at<uchar>(y, x) = saturate_cast<uchar>(val);
        }
    }
    return background;
}

// 1차/2차 모델을 이용해 조명 보정 및 이진화 결과 비교
void run_model_quad(const std::string& img_path) {
    // 1. 영상 불러오기
    Mat img = imread(img_path, IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << "Failed to load image: " << img_path << std::endl;
        return;
    }

    // 2. 1차 모델 적용
    Mat bg_linear = estimate_background(img, false);
    Mat corrected_linear = compute_difference_inverse(img, bg_linear);
    Mat binary_linear;
    threshold(corrected_linear, binary_linear, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // 1차 결과 저장
    imwrite("result_plane_background.png", bg_linear);
    imwrite("result_plane_otsu.png", binary_linear);

    // 3. 2차 모델 적용
    Mat bg_quad = estimate_background(img, true);
    Mat corrected_quad = compute_difference_inverse(img, bg_quad);
    Mat binary_quad;
    threshold(corrected_quad, binary_quad, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // 2차 결과 저장
    imwrite("result_quad_background.png", bg_quad);
    imwrite("result_quad_otsu.png", binary_quad);

    // 4. 결과 시각화 (각 모델의 배경, 이진화 영상)
    imshow("Background - First Order", bg_linear);
    imshow("Otsu - First Order", binary_linear);
    imshow("Background - Second Order", bg_quad);
    imshow("Otsu - Second Order", binary_quad);

    waitKey(0);
}
