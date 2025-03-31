#include <opencv2/opencv.hpp>
#include <iostream>
#include "SobelCircuitDemo.h"

using namespace cv;
using namespace std;

void runSobelCircuitDemo() {
    // 1. ȸ�� ���� �ҷ�����
    Mat src = imread("circuit.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "circuit.bmp �̹����� �� �� �����ϴ�!" << endl;
        return;
    }

    // 2. Sobel ���͸� ���� X, Y ���� ��� ����
    Mat gradX, gradY, magnitude, magnitude8;
    Sobel(src, gradX, CV_32F, 1, 0);  // X����
    Sobel(src, gradY, CV_32F, 0, 1);  // Y����

    // 3. gradient magnitude ���
    magnitude = abs(gradX) + abs(gradY);
    magnitude.convertTo(magnitude8, CV_8U); // 8��Ʈ�� ��ȯ

    // 4. ������ ���ſ� Gaussian Blur �߰�
    GaussianBlur(magnitude8, magnitude8, Size(3, 3), 1.0);

    // 5. ���� �Ӱ谪 ����ȭ (�ʹ� ���� �ʵ��� ����!)
    Mat binary;
    threshold(magnitude8, binary, 100, 255, THRESH_BINARY);

    // 6. ��� ���
    imshow("Original Circuit", src);
    moveWindow("Original Circuit", 100, 100);

    imshow("Sobel Edge", magnitude8);
    moveWindow("Sobel Edge", 750, 100);

    imshow("Binary Edge Result", binary);
    moveWindow("Binary Edge Result", 1400, 100);

    waitKey(0);

    // �޸� ����
    src.release();
    gradX.release();
    gradY.release();
    magnitude.release();
    magnitude8.release();
    binary.release();
}
