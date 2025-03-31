#include <opencv2/opencv.hpp>  // OpenCV �⺻ ���̺귯��
#include <iostream>            // �ܼ� ����¿�
#include <string>              // ���ڿ� ó��
#include <iomanip>             // ���� ���� ������
#include <sstream>             // ���ڿ� ��Ʈ�� ó����
#include "LaneDemo.h"          // �Լ� ���� ������ �������

using namespace cv;            // OpenCV ���ӽ����̽� ���
using namespace std;           // ǥ�� ���ӽ����̽� ���

// ���� ���� �Լ�
void runLaneDemo() {
    string folder = "./Lane1/"; // ���� �̹����� ����� ���� ���

    for (int i = 1; i <= 12; i++) { // 1�� ~ 12�� �̹��� ��ȸ
        stringstream ss;
        ss << folder << setfill('0') << setw(5) << i << ".jpg"; // ���ϸ� ������: 00001.jpg
        string filename = ss.str();

        Mat src = imread(filename, IMREAD_GRAYSCALE); // �׷��̽����Ϸ� �̹��� �б�
        if (src.empty()) {
            cout << "�̹����� �ҷ��� �� �����ϴ�: " << filename << endl;
            continue;
        }

        // Sobel ������ ���� ���� ����
        Mat gradX, gradY, magnitude, angle, mask;

        // X, Y ���� Sobel ���� ���� �� ���� ����� ���� ����
        Sobel(src, gradX, CV_32F, 1, 0); // x�� �̺�
        Sobel(src, gradY, CV_32F, 0, 1); // y�� �̺�

        // magnitude: ���� ����, angle: ���� (�� ����)
        cartToPolar(gradX, gradY, magnitude, angle, true); // true �� �� ���� ��ȯ

        mask = Mat::zeros(src.size(), CV_8UC1); // ���� ����� ������ ����ũ (0���� �ʱ�ȭ)
        int imgCenter = src.cols / 2;           // �̹��� �߽� x��ǥ
        int horizon = src.rows / 2;             // ȭ�� �߰� y��ǥ (��� ����)

        // �̹��� ��ü �ȼ� �ݺ�
        for (int y = 0; y < src.rows; y++) {
            for (int x = 0; x < src.cols; x++) {
                float ang = angle.at<float>(y, x);     // �ش� �ȼ��� ����
                float mag = magnitude.at<float>(y, x); // �ش� �ȼ��� ���� ����

                if (y < horizon) continue; // ��� ���� ���� (������ �ϴܿ��� ����)

                // ���� ���� ����: �߽� ����, ���� ���� ���, ���� ����
                if (x < imgCenter && mag > 60 && ang >= 30 && ang <= 50)
                    mask.at<uchar>(y, x) = 255; // ��� ǥ�� (�������� �ν�)

                // ������ ���� ����: �߽� ������, ��Ī������ ���� ���� Ȯ��
                if (x >= imgCenter && mag > 60 && ang >= 118 && ang <= 155)
                    mask.at<uchar>(y, x) = 255;
            }
        }

        // ROI ����ũ ����: �ϴ��� �� ��縸 ���� (���ʿ��� ���� ����)
        Mat roiMask = Mat::zeros(src.size(), CV_8UC1); // ROI �ʱ�ȭ
        int w = src.cols, h = src.rows;

        // ROI ���� ������ ���� (���� V�� ����)
        Point roiPts[1][4] = {
            { Point(w * 0.02, h), Point(w * 0.35, h * 0.52),
              Point(w * 0.65, h * 0.52), Point(w * 0.98, h) }
        };

        const Point* ppt[1] = { roiPts[0] }; // ������ ������ �迭
        int npt[] = { 4 };                  // ������ ����

        // ROI ä���
        fillPoly(roiMask, ppt, npt, 1, Scalar(255)); // ROI ������ ������� ä��

        // ROI ���� ���� ���� ����� �����
        bitwise_and(mask, roiMask, mask);

        // ��� ���
        imshow("Original Frame", src);       // ���� ���� ���
        imshow("Detected Lane Pixels", mask); // ���� ���� ��� ���
        waitKey(200); // ���� �̹����� �Ѿ�� �� 0.2�� ���
    }

    destroyAllWindows(); // ��� â �ݱ�
}
