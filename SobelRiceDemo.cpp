#include <opencv2/opencv.hpp>
#include <iostream>
#include "SobelRiceDemo.h"

using namespace cv;
using namespace std;

void runSobelRiceDemo() {
    // 1. �̹��� �ε�
    Mat src = imread("rice.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "rice.bmp �̹����� �� �� �����ϴ�!" << endl;
        return;
    }

    // 2. ����þ� ���� ������ ����
    GaussianBlur(src, src, Size(5, 5), 1.0);

    // 3. Sobel ���� ���� (X, Y)
    Mat gradX, gradY, grad, gradAbs, binary;
    Sobel(src, gradX, CV_16S, 1, 0);
    Sobel(src, gradY, CV_16S, 0, 1);

    // 4. X�� Y ���� ����
    addWeighted(gradX, 0.5, gradY, 0.5, 0, grad);

    // 5. ���� ���� ���� �� 8��Ʈ ��ȯ
    convertScaleAbs(grad, gradAbs, 3.0);  // gain 3.0

    // 6. ����ȭ (Threshold = 50)
    threshold(gradAbs, binary, 50, 255, THRESH_BINARY);

    // 7. ��� ���
    imshow("Original Rice", src);
    moveWindow("Original Rice", 100, 100);

    imshow("Sobel Edge", gradAbs);
    moveWindow("Sobel Edge", 700, 100);

    imshow("Binary Edge Result", binary);
    moveWindow("Binary Edge Result", 1300, 100);

    waitKey(0);

    // �޸� ����
    src.release();
    gradX.release();
    gradY.release();
    grad.release();
    gradAbs.release();
    binary.release();
}
