#include <opencv2/opencv.hpp>
#include <iostream>
#include "GrayMorphologyDemo.h"

using namespace cv;
using namespace std;

void runGrayMorphologyDemo() {
    // lena.bmp 영상 로드 (그레이스케일)
    Mat src = imread("lena.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "lena.bmp 이미지를 불러올 수 없습니다!" << endl;
        return;
    }

    // 구조 요소 정의 (5x5 정방형)
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));

    // 침식 및 팽창 결과 저장용
    Mat eroded, dilated;

    // 그레이 영상에 대한 형태학적 침식 및 팽창 연산 수행
    erode(src, eroded, element);
    dilate(src, dilated, element);

    // 원본 및 결과 출력
    imshow("Original Image", src);
    moveWindow("Original Image", 100, 100);

    imshow("Eroded (Gray)", eroded);
    moveWindow("Eroded (Gray)", 500, 100);

    imshow("Dilated (Gray)", dilated);
    moveWindow("Dilated (Gray)", 900, 100);

    waitKey(0);
    destroyAllWindows();
}
