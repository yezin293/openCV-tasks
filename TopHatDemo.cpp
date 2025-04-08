#include <opencv2/opencv.hpp>
#include <iostream>
#include "TopHatDemo.h"

using namespace cv;
using namespace std;

void runTopHatDemo() {
    // �̹��� �ε� (�׷��̽�����)
    Mat src = imread("rice.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "rice.bmp �̹����� �ҷ��� �� �����ϴ�!" << endl;
        return;
    }

    // Structuring Element ���� (�⺻�� 15x15)
    Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));

    // Top-hat ���� ����
    Mat tophat;
    morphologyEx(src, tophat, MORPH_TOPHAT, element);

    // Otsu ����ȭ - Top-hat ó�� ��
    Mat otsuOriginal;
    threshold(src, otsuOriginal, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // Otsu ����ȭ - Top-hat ó�� ��
    Mat otsuTophat;
    threshold(tophat, otsuTophat, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // ��� ���
    imshow("1. ���� ����", src);
    moveWindow("1. ���� ����", 100, 100);

    imshow("2. Top-hat ���� ���", tophat);
    moveWindow("2. Top-hat ���� ���", 500, 100);

    imshow("3. Otsu ����ȭ (����)", otsuOriginal);
    moveWindow("3. Otsu ����ȭ (����)", 100, 400);

    imshow("4. Otsu ����ȭ (Top-hat ��)", otsuTophat);
    moveWindow("4. Otsu ����ȭ (Top-hat ��)", 500, 400);

    waitKey(0);
    destroyAllWindows();
}
