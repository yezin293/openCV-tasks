#include <opencv2/opencv.hpp>  // OpenCV 기본 헤더
#include <iostream>            // 콘솔 입출력
#include <cmath>               // 수학 함수 (sin 등)
#include "WarpingDemo.h"       // 함수 선언 헤더

using namespace cv;
using namespace std;

// [4번] 영상 왜곡(Warping) 실습 함수
// - 역방향 사상을 이용해 수평 방향의 sinusoidal 왜곡을 구현함
void runWarpingDemo() {
    Mat src = imread("lena.bmp", IMREAD_GRAYSCALE);  // 입력 영상 로드 (그레이스케일)
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return;
    }

    // 결과 영상을 동일한 크기와 타입으로 초기화
    Mat dst = Mat::zeros(src.size(), src.type());

    // y 좌표에 따라 x 방향으로 sin 곡선을 적용하여 수평 왜곡
    // (역방향 사상) x' = x + 20 * sin(2πy / 180)
    for (int y = 0; y < dst.rows; y++) {
        for (int x = 0; x < dst.cols; x++) {
            // 원본 좌표를 계산 (역방향 사상)
            int newX = static_cast<int>(x - 20.0 * sin(2 * CV_PI * y / 180.0));

            // newX가 유효한 영역 내일 때만 복사
            if (newX >= 0 && newX < src.cols) {
                dst.at<uchar>(y, x) = src.at<uchar>(y, newX);
            }
        }
    }

    // 결과 출력
    imshow("src", src);    // 원본 영상
    imshow("dst", dst);    // 왜곡된 영상
    waitKey(0);
}
