#include <opencv2/opencv.hpp>
#include <iostream>
#include "MirrorDemo.h"

using namespace cv;
using namespace std;

void runMirrorDemo() {
    Mat src = imread("lena.bmp", IMREAD_GRAYSCALE); // 흑백 영상 로드

    if (src.empty()) {
        cout << "영상을 불러올 수 없습니다!" << endl;
        return;
    }

    Mat horizontal, vertical;
    flip(src, horizontal, 1); // 수평 미러링
    flip(src, vertical, 0);   // 수직 미러링

    // 출력
    imshow("Original", src);
    moveWindow("Original", 100, 100);

    imshow("Horizontal Mirror", horizontal);
    moveWindow("Horizontal Mirror", 450, 100);

    imshow("Vertical Mirror", vertical);
    moveWindow("Vertical Mirror", 800, 100);

    waitKey(0);
    destroyAllWindows();
}