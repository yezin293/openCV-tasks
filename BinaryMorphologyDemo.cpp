#include <opencv2/opencv.hpp>
#include <iostream>
#include "BinaryMorphologyDemo.h"

using namespace cv;
using namespace std;

// 이진 영상의 팽창과 침식 실습
void runBinaryMorphologyDemo() {
    Mat src = imread("fingerprint.bmp", IMREAD_GRAYSCALE); // 이진 영상

    if (src.empty()) {
        cout << "fingerprint.bmp 이미지를 불러올 수 없습니다!" << endl;
        return;
    }

    Mat erosionResult, dilationResult;

    // 3x3 구조 요소 생성 (사각형)
    Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

    // 침식 연산
    erode(src, erosionResult, element);

    // 팽창 연산
    dilate(src, dilationResult, element);

    // 결과 출력
    imshow("Original (Binary)", src);
    imshow("Erosion Result", erosionResult);
    imshow("Dilation Result", dilationResult);

    moveWindow("Original (Binary)", 100, 100);
    moveWindow("Erosion Result", 500, 100);
    moveWindow("Dilation Result", 900, 100);

    waitKey(0);
    destroyAllWindows();
}
