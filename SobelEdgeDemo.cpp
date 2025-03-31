#include <opencv2/opencv.hpp>   // OpenCV ���� ó�� �⺻ ���
#include <iostream>             // ǥ�� ����� ���
#include "SobelEdgeDemo.h"      // �Լ� ���� ��� ����

using namespace cv;             // OpenCV ���ӽ����̽� ���
using namespace std;            // ǥ�� ���ӽ����̽� ���

// Sobel ���͸� �̿��� ���� ���� �Լ� ����
void runSobelEdgeDemo() {
    // �׷��̽����� �̹��� �ε� (lenna.jpg)
    Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);

    // �̹��� �ε� ���� �� ���� �޽��� ��� �� �Լ� ����
    if (src.empty()) {
        cout << "�̹����� �ҷ��� �� �����ϴ�!" << endl;
        return;
    }

    // ���� ����� ������ ���� ����
    Mat sobel16, sobel8;

    // Sobel ���� (1�� �̺�, X+Y ����), ����� 16��Ʈ signed Ÿ�Կ� ����
    Sobel(src, sobel16, CV_16S, 1, 1);

    // ����� �ð�ȭ ������ 8��Ʈ�� ��ȯ
    // scale = 1, offset = 0
    convertScaleAbs(sobel16, sobel8, 1, 0);

    // ���� �̹��� ���
    imshow("Original Image", src);
    moveWindow("Original Image", 100, 100); // â ��ġ ����

    // ���� ���� ��� ���
    imshow("Sobel Edge Image", sobel8);
    moveWindow("Sobel Edge Image", 750, 100); // â ��ġ ����

    // Ű �Է� ��� (����ڰ� â �ݱ� ������)
    waitKey(0);

    // �޸� ����
    src.release();
    sobel16.release();
    sobel8.release();
}
