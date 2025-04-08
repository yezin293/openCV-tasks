#include <opencv2/opencv.hpp>
#include <iostream>
#include "OpenCloseMorphologyDemo.h"

using namespace cv;
using namespace std;

void runOpenCloseMorphologyDemo() {
    Mat src = imread("fingerprint.bmp", IMREAD_GRAYSCALE); // ���� ����

    if (src.empty()) {
        cout << "fingerprint.bmp �̹����� �ҷ��� �� �����ϴ�!" << endl;
        return;
    }

    Mat openResult, closeResult;

    // ���� ��� ���� (3x3 �簢��)
    Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));

    // Open ����: ħ�� �� ��â
    morphologyEx(src, openResult, MORPH_OPEN, element);

    // Close ����: ��â �� ħ��
    morphologyEx(src, closeResult, MORPH_CLOSE, element);

    // ��� ���
    imshow("Original", src);
    imshow("Open Operation", openResult);
    imshow("Close Operation", closeResult);

    moveWindow("Original", 100, 100);
    moveWindow("Open Operation", 500, 100);
    moveWindow("Close Operation", 900, 100);

    waitKey(0);
    destroyAllWindows();
}
