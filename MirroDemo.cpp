#include <opencv2/opencv.hpp>
#include <iostream>
#include "MirrorDemo.h"

using namespace cv;
using namespace std;

void runMirrorDemo() {
    Mat src = imread("lena.bmp", IMREAD_GRAYSCALE); // ��� ���� �ε�

    if (src.empty()) {
        cout << "������ �ҷ��� �� �����ϴ�!" << endl;
        return;
    }

    Mat horizontal, vertical;
    flip(src, horizontal, 1); // ���� �̷���
    flip(src, vertical, 0);   // ���� �̷���

    // ���
    imshow("Original", src);
    moveWindow("Original", 100, 100);

    imshow("Horizontal Mirror", horizontal);
    moveWindow("Horizontal Mirror", 450, 100);

    imshow("Vertical Mirror", vertical);
    moveWindow("Vertical Mirror", 800, 100);

    waitKey(0);
    destroyAllWindows();
}