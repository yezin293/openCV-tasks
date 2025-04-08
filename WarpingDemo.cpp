#include <opencv2/opencv.hpp>  // OpenCV �⺻ ���
#include <iostream>            // �ܼ� �����
#include <cmath>               // ���� �Լ� (sin ��)
#include "WarpingDemo.h"       // �Լ� ���� ���

using namespace cv;
using namespace std;

// [4��] ���� �ְ�(Warping) �ǽ� �Լ�
// - ������ ����� �̿��� ���� ������ sinusoidal �ְ��� ������
void runWarpingDemo() {
    Mat src = imread("lena.bmp", IMREAD_GRAYSCALE);  // �Է� ���� �ε� (�׷��̽�����)
    if (src.empty()) {
        cout << "�̹����� �ҷ��� �� �����ϴ�." << endl;
        return;
    }

    // ��� ������ ������ ũ��� Ÿ������ �ʱ�ȭ
    Mat dst = Mat::zeros(src.size(), src.type());

    // y ��ǥ�� ���� x �������� sin ��� �����Ͽ� ���� �ְ�
    // (������ ���) x' = x + 20 * sin(2��y / 180)
    for (int y = 0; y < dst.rows; y++) {
        for (int x = 0; x < dst.cols; x++) {
            // ���� ��ǥ�� ��� (������ ���)
            int newX = static_cast<int>(x - 20.0 * sin(2 * CV_PI * y / 180.0));

            // newX�� ��ȿ�� ���� ���� ���� ����
            if (newX >= 0 && newX < src.cols) {
                dst.at<uchar>(y, x) = src.at<uchar>(y, newX);
            }
        }
    }

    // ��� ���
    imshow("src", src);    // ���� ����
    imshow("dst", dst);    // �ְ�� ����
    waitKey(0);
}
