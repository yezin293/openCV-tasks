#include <opencv2/opencv.hpp>
#include <iostream>
#include "SobelCircuitDemo.h"

using namespace cv;
using namespace std;

void runSobelCircuitDemo() {
    // 1. 회로 영상 불러오기
    Mat src = imread("circuit.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "circuit.bmp 이미지를 열 수 없습니다!" << endl;
        return;
    }

    // 2. Sobel 필터를 통해 X, Y 방향 경계 검출
    Mat gradX, gradY, magnitude, magnitude8;
    Sobel(src, gradX, CV_32F, 1, 0);  // X방향
    Sobel(src, gradY, CV_32F, 0, 1);  // Y방향

    // 3. gradient magnitude 계산
    magnitude = abs(gradX) + abs(gradY);
    magnitude.convertTo(magnitude8, CV_8U); // 8비트로 변환

    // 4. 노이즈 제거용 Gaussian Blur 추가
    GaussianBlur(magnitude8, magnitude8, Size(3, 3), 1.0);

    // 5. 수동 임계값 이진화 (너무 낮지 않도록 설정!)
    Mat binary;
    threshold(magnitude8, binary, 100, 255, THRESH_BINARY);

    // 6. 결과 출력
    imshow("Original Circuit", src);
    moveWindow("Original Circuit", 100, 100);

    imshow("Sobel Edge", magnitude8);
    moveWindow("Sobel Edge", 750, 100);

    imshow("Binary Edge Result", binary);
    moveWindow("Binary Edge Result", 1400, 100);

    waitKey(0);

    // 메모리 해제
    src.release();
    gradX.release();
    gradY.release();
    magnitude.release();
    magnitude8.release();
    binary.release();
}
