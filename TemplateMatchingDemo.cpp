#include <opencv2/opencv.hpp>
#include <iostream>
#include "TemplateMatchingDemo.h"

using namespace std;
using namespace cv;

// �پ��� ���ø� ��Ī ������ �����Ͽ� ���� ������ Ž���ϰ� ���ϴ� �Լ�
void runTemplateMatchingDemo() {
    // ---------------- Lena ��Ī ----------------

    // Lena �̹��� �ҷ����� (�׷��̽����� �� �÷�)
    Mat lena_gray = imread("lena.bmp", IMREAD_GRAYSCALE);
    Mat lena_color = imread("lena.bmp", IMREAD_COLOR);
    // Lena�� ���� ���ø� �̹��� �ҷ�����
    Mat lena_ref = imread("lena_ref.bmp", IMREAD_GRAYSCALE);
    if (lena_gray.empty() || lena_ref.empty() || lena_color.empty()) {
        cout << "lena �̹��� �ε� ����!" << endl;
        return;
    }

    // TM_SQDIFF ���: ���̰��� �������� �������� �ּҰ� ��ġ Ž��
    Mat res1;
    matchTemplate(lena_gray, lena_ref, res1, TM_SQDIFF);
    Point minLoc1;
    minMaxLoc(res1, nullptr, nullptr, &minLoc1, nullptr);
    // ��Ī ��� ǥ�� (���� �簢��)
    Mat lena1 = lena_color.clone();
    rectangle(lena1, minLoc1,
        Point(minLoc1.x + lena_ref.cols, minLoc1.y + lena_ref.rows),
        Scalar(0, 0, 255), 2);
    imshow("Lena - TM_SQDIFF", lena1);
    imshow("Template - Lena", lena_ref);

    // TM_CCOEFF ���: ��� ����� �������� �ִ밪 ��ġ Ž��
    Mat res2;
    matchTemplate(lena_gray, lena_ref, res2, TM_CCOEFF);
    Point maxLoc2;
    minMaxLoc(res2, nullptr, nullptr, nullptr, &maxLoc2);
    // ��Ī ��� ǥ�� (�Ķ� �簢��)
    Mat lena2 = lena_color.clone();
    rectangle(lena2, maxLoc2,
        Point(maxLoc2.x + lena_ref.cols, maxLoc2.y + lena_ref.rows),
        Scalar(255, 0, 0), 2);
    imshow("Lena - TM_CCOEFF", lena2);

    // ---------------- Test1 ��Ī ----------------

    // Test1 �̹��� �� ���� ���ø� �ҷ�����
    Mat test1 = imread("test1.bmp", IMREAD_COLOR);
    Mat temp1 = imread("test1_ref.bmp", IMREAD_GRAYSCALE);
    Mat test1_gray;
    cvtColor(test1, test1_gray, COLOR_BGR2GRAY);
    if (test1.empty() || temp1.empty()) {
        cout << "test1 �̹��� �ε� ����!" << endl;
        return;
    }

    // TM_SQDIFF ������� ��Ī ����
    Mat res3;
    matchTemplate(test1_gray, temp1, res3, TM_SQDIFF);
    Point minLoc3;
    minMaxLoc(res3, nullptr, nullptr, &minLoc3, nullptr);
    Mat test1_draw = test1.clone();
    rectangle(test1_draw, minLoc3,
        Point(minLoc3.x + temp1.cols, minLoc3.y + temp1.rows),
        Scalar(0, 0, 255), 2);
    imshow("Test1 - TM_SQDIFF", test1_draw);
    imshow("Template - Test1", temp1);

    // ---------------- Test2 ��Ī ----------------

    // Test2 �̹��� �� ���ø� �ҷ�����
    Mat test2 = imread("test2.bmp", IMREAD_COLOR);
    Mat temp2 = imread("test2_ref.bmp", IMREAD_GRAYSCALE);
    Mat test2_gray;
    cvtColor(test2, test2_gray, COLOR_BGR2GRAY);
    if (test2.empty() || temp2.empty()) {
        cout << "test2 �̹��� �ε� ����!" << endl;
        return;
    }

    // TM_SQDIFF ������� ��Ī ����
    Mat res4;
    matchTemplate(test2_gray, temp2, res4, TM_SQDIFF);
    Point minLoc4;
    minMaxLoc(res4, nullptr, nullptr, &minLoc4, nullptr);
    Mat test2_draw = test2.clone();
    rectangle(test2_draw, minLoc4,
        Point(minLoc4.x + temp2.cols, minLoc4.y + temp2.rows),
        Scalar(0, 0, 255), 2);
    imshow("Test2 - TM_SQDIFF", test2_draw);
    imshow("Template - Test2", temp2);

    // Ű �Է� ��� �� ����
    waitKey(0);
    destroyAllWindows();
}
