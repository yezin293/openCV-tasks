#include <opencv2/opencv.hpp>     // OpenCV ���� ó�� ���
#include <iostream>               // ǥ�� �����
#include "MedianBlurDemo.h"       // MedianBlur �Լ� ���� ���

using namespace cv;               // OpenCV ���ӽ����̽�
using namespace std;              // ǥ�� ���ӽ����̽�

// MedianBlur �ǽ� �Լ� ����
void runMedianBlurDemo() {
    // �÷� �̹��� �ε� (lenna.jpg ���)
    Mat src = imread("lenna.jpg", IMREAD_COLOR);

    // �̹��� �ε� ���� �� ���� �޽��� ��� �� ����
    if (src.empty()) {
        cout << "�̹����� �ҷ��� �� �����ϴ�!" << endl;
        return;
    }

    Mat dst; // ��� �̹��� ���� ����

    int mode;
    // ����ڿ��� ��� ���� �ޱ�
    cout << "\n[MedianBlur ���� ��� ����]\n";
    cout << "1. Ŀ�� ũ�� �ڵ� ���� (3~25)\n";
    cout << "2. ���� Ŀ�� ũ�� �Է��ؼ� ����\n";
    cout << "���� >> ";
    cin >> mode;

    // ���� ���� ���÷���
    imshow("Original Image", src);
    moveWindow("Original Image", 100, 100);

    // Mode 1: Ŀ�� ũ�⸦ �ڵ����� 3���� 25���� Ȧ���� ������Ű�� ���� ����
    if (mode == 1) {
        for (int ksize = 3; ksize <= 25; ksize += 2) {
            medianBlur(src, dst, ksize);             // �̵�� ���� ����
            imshow("Median Filter Result", dst);     // ��� ���� ���
            moveWindow("Median Filter Result", 750, 100); // â ��ġ ����
            waitKey(50); // ������ �Ѿ���� waitTime ���� (0.05��)
        }
    }
    // Mode 2: ����ڰ� ���ϴ� Ŀ�� ũ�⸦ �Է��ؼ� ���� ����
    else if (mode == 2) {
        int ksize;
        cout << "������ Ŀ�� ũ��(Ȧ��)�� �Է��ϼ���: ";
        cin >> ksize;

        // Ȧ�� & 3 �̻����� ��ȿ�� �˻�
        if (ksize % 2 == 0 || ksize < 3) {
            cout << "?? Ŀ�� ũ��� 3 �̻��� Ȧ������ �մϴ�.\n";
            return;
        }

        medianBlur(src, dst, ksize);                 // ���� ����
        imshow("Median Filter Result", dst);         // ��� ���
        moveWindow("Median Filter Result", 750, 100);
        waitKey(0); // ��� Ȯ���� ������ ���
    }
    // �߸��� ���� �� �ȳ�
    else {
        cout << "�߸��� �����Դϴ�.\n";
    }

    // �޸� ����
    src.release();
    dst.release();
}
