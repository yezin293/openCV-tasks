#include <opencv2/opencv.hpp>
#include <iostream>]
#include "AffineTransformDemo.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void runGeoTransformDemo() {
    // 1. 원본 이미지 불러오기
    Mat src = imread("lenna.jpg");
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다!" << endl;
        return;
    }

    // 2. (100, 100)으로 평행이동 행렬 (2x3)
    Mat shiftMat = Mat::eye(2, 3, CV_64F);
    shiftMat.at<double>(0, 2) = 100;
    shiftMat.at<double>(1, 2) = 100;

    // 3. 이동 적용
    Mat shifted;
    warpAffine(src, shifted, shiftMat, src.size());

    // 4. 이동된 영상에 대해, 원래 중심 기준으로 45도 회전 행렬 생성
    Point2f center(src.cols / 2.0f, src.rows / 2.0f);
    Mat rotateMat = getRotationMatrix2D(center, 45, 1.0);

    // 5. 회전 적용
    Mat result;
    warpAffine(shifted, result, rotateMat, src.size());

    // 6. 결과 출력
    imshow("Result (Shift + Rotate)", result);
    waitKey(0);
}
