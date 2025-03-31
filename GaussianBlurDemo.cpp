#include <opencv2/opencv.hpp>   // OpenCV �⺻ ��� (���� ó����)
#include <iostream>             // ǥ�� ����� ���̺귯��
#include "GaussianBlurDemo.h"  // ������� ���� (�Լ� ����)

using namespace cv;             // OpenCV ���ӽ����̽� ���
using namespace std;           // std ���ӽ����̽� ���

// ����þ� ���� ���� �Լ� ����
void runGaussianBlurDemo() {
    // �÷� �̹��� �ҷ����� (lenna.jpg ���)
    Mat src = imread("lenna.jpg", IMREAD_COLOR);

    // �̹��� �ε� ���� �� ���� �޽��� ��� �� ����
    if (src.empty()) {
        cout << "�̹����� �ҷ��� �� �����ϴ�!" << endl;
        return;
    }

    Mat dst; // ��� ���� �����

    // ����ڿ��� ��� ���� �ޱ�
    int mode;
    cout << "\n[GaussianBlur ���� ��� ����]\n";
    cout << "1. Ŀ�� ũ�� �����ϸ� ���� (sigma �ڵ�)\n";
    cout << "2. sigmaX, sigmaY ���� ���� (Size �ڵ�)\n";
    cout << "���� >> ";
    cin >> mode;

    // ���� ���� ���÷���
    imshow("Original Image", src);
    moveWindow("Original Image", 100, 100);

    // Mode 1: Ŀ�� ũ�⸦ ���� Ű��鼭 GaussianBlur ����
    if (mode == 1) {
        for (int i = 1; i < 61; i += 2) { // Ŀ�� ũ�� 1~59���� Ȧ���� ����
            GaussianBlur(src, dst, Size(i, i), 0, 0); // sigma �ڵ� ���
            imshow("Gaussian Filter Result", dst);   // ��� ���� ���
            moveWindow("Gaussian Filter Result", 750, 100); // â ��ġ ����
            waitKey(50); // 0.05�� ��� �� ���� Ŀ�η� ���� (����� ������)
        }
    }

    // Mode 2: sigmaX, sigmaY ���� ���� �Է¹޾Ƽ� ���� ����
    else if (mode == 2) {
        double sigmaX, sigmaY;
        cout << "sigmaX ���� �Է��ϼ���: ";
        cin >> sigmaX;
        cout << "sigmaY ���� �Է��ϼ���: ";
        cin >> sigmaY;

        // Ŀ�� ũ�� �ڵ� ���� (Size = 0), �Էµ� �ñ׸������� ����
        GaussianBlur(src, dst, Size(0, 0), sigmaX, sigmaY);
        imshow("Gaussian Filter Result", dst);
        moveWindow("Gaussian Filter Result", 750, 100);
        waitKey(0); // Ű �Է� ��ٸ� (���� ���� ������ ���)
    }

    // �߸��� ���� �Է� �� ó��
    else {
        cout << "�߸��� �Է��Դϴ�.\n";
    }

    // �޸� ����
    src.release();
    dst.release();
}
