#include <opencv2/opencv.hpp>
#include <iostream>
#include "TopHatDemo.h"

using namespace cv;
using namespace std;

void runTopHatDemo() {
    // 이미지 로드 (그레이스케일)
    Mat src = imread("rice.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "rice.bmp 이미지를 불러올 수 없습니다!" << endl;
        return;
    }

    // Structuring Element 생성 (기본은 15x15)
    Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));

    // Top-hat 연산 수행
    Mat tophat;
    morphologyEx(src, tophat, MORPH_TOPHAT, element);

    // Otsu 이진화 - Top-hat 처리 전
    Mat otsuOriginal;
    threshold(src, otsuOriginal, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // Otsu 이진화 - Top-hat 처리 후
    Mat otsuTophat;
    threshold(tophat, otsuTophat, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // 결과 출력
    imshow("1. 원본 영상", src);
    moveWindow("1. 원본 영상", 100, 100);

    imshow("2. Top-hat 연산 결과", tophat);
    moveWindow("2. Top-hat 연산 결과", 500, 100);

    imshow("3. Otsu 이진화 (원본)", otsuOriginal);
    moveWindow("3. Otsu 이진화 (원본)", 100, 400);

    imshow("4. Otsu 이진화 (Top-hat 후)", otsuTophat);
    moveWindow("4. Otsu 이진화 (Top-hat 후)", 500, 400);

    waitKey(0);
    destroyAllWindows();
}
