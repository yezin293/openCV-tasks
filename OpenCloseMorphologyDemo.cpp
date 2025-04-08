#include <opencv2/opencv.hpp>
#include <iostream>
#include "OpenCloseMorphologyDemo.h"

using namespace cv;
using namespace std;

void runOpenCloseMorphologyDemo() {
    Mat src = imread("fingerprint.bmp", IMREAD_GRAYSCALE); // 이진 영상

    if (src.empty()) {
        cout << "fingerprint.bmp 이미지를 불러올 수 없습니다!" << endl;
        return;
    }

    Mat openResult, closeResult;

    // 구조 요소 정의 (3x3 사각형)
    Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));

    // Open 연산: 침식 후 팽창
    morphologyEx(src, openResult, MORPH_OPEN, element);

    // Close 연산: 팽창 후 침식
    morphologyEx(src, closeResult, MORPH_CLOSE, element);

    // 결과 출력
    imshow("Original", src);
    imshow("Open Operation", openResult);
    imshow("Close Operation", closeResult);

    moveWindow("Original", 100, 100);
    moveWindow("Open Operation", 500, 100);
    moveWindow("Close Operation", 900, 100);

    waitKey(0);
    destroyAllWindows();
}
