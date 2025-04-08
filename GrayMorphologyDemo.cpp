#include <opencv2/opencv.hpp>
#include <iostream>
#include "GrayMorphologyDemo.h"

using namespace cv;
using namespace std;

void runGrayMorphologyDemo() {
    // lena.bmp ���� �ε� (�׷��̽�����)
    Mat src = imread("lena.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "lena.bmp �̹����� �ҷ��� �� �����ϴ�!" << endl;
        return;
    }

    // ���� ��� ���� (5x5 ������)
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));

    // ħ�� �� ��â ��� �����
    Mat eroded, dilated;

    // �׷��� ���� ���� �������� ħ�� �� ��â ���� ����
    erode(src, eroded, element);
    dilate(src, dilated, element);

    // ���� �� ��� ���
    imshow("Original Image", src);
    moveWindow("Original Image", 100, 100);

    imshow("Eroded (Gray)", eroded);
    moveWindow("Eroded (Gray)", 500, 100);

    imshow("Dilated (Gray)", dilated);
    moveWindow("Dilated (Gray)", 900, 100);

    waitKey(0);
    destroyAllWindows();
}
