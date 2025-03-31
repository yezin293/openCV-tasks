#include <opencv2/opencv.hpp>
#include <iostream>
#include "SobelRiceDemo.h"

using namespace cv;
using namespace std;

void runSobelRiceDemo() {
    // 1. 이미지 로딩
    Mat src = imread("rice.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "rice.bmp 이미지를 열 수 없습니다!" << endl;
        return;
    }

    // 2. 가우시안 블러로 노이즈 제거
    GaussianBlur(src, src, Size(5, 5), 1.0);

    // 3. Sobel 에지 검출 (X, Y)
    Mat gradX, gradY, grad, gradAbs, binary;
    Sobel(src, gradX, CV_16S, 1, 0);
    Sobel(src, gradY, CV_16S, 0, 1);

    // 4. X와 Y 방향 결합
    addWeighted(gradX, 0.5, gradY, 0.5, 0, grad);

    // 5. 에지 강도 강조 후 8비트 변환
    convertScaleAbs(grad, gradAbs, 3.0);  // gain 3.0

    // 6. 이진화 (Threshold = 50)
    threshold(gradAbs, binary, 50, 255, THRESH_BINARY);

    // 7. 결과 출력
    imshow("Original Rice", src);
    moveWindow("Original Rice", 100, 100);

    imshow("Sobel Edge", gradAbs);
    moveWindow("Sobel Edge", 700, 100);

    imshow("Binary Edge Result", binary);
    moveWindow("Binary Edge Result", 1300, 100);

    waitKey(0);

    // 메모리 해제
    src.release();
    gradX.release();
    gradY.release();
    grad.release();
    gradAbs.release();
    binary.release();
}
