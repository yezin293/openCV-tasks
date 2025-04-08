#include <opencv2/opencv.hpp>
#include <iostream>
#include "BinaryMorphologyDemo.h"

using namespace cv;
using namespace std;

// ���� ������ ��â�� ħ�� �ǽ�
void runBinaryMorphologyDemo() {
    Mat src = imread("fingerprint.bmp", IMREAD_GRAYSCALE); // ���� ����

    if (src.empty()) {
        cout << "fingerprint.bmp �̹����� �ҷ��� �� �����ϴ�!" << endl;
        return;
    }

    Mat erosionResult, dilationResult;

    // 3x3 ���� ��� ���� (�簢��)
    Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

    // ħ�� ����
    erode(src, erosionResult, element);

    // ��â ����
    dilate(src, dilationResult, element);

    // ��� ���
    imshow("Original (Binary)", src);
    imshow("Erosion Result", erosionResult);
    imshow("Dilation Result", dilationResult);

    moveWindow("Original (Binary)", 100, 100);
    moveWindow("Erosion Result", 500, 100);
    moveWindow("Dilation Result", 900, 100);

    waitKey(0);
    destroyAllWindows();
}
