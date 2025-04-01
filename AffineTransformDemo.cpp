#include <opencv2/opencv.hpp>
#include <iostream>]
#include "AffineTransformDemo.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void runGeoTransformDemo() {
    // 1. ���� �̹��� �ҷ�����
    Mat src = imread("lenna.jpg");
    if (src.empty()) {
        cout << "�̹����� �ҷ��� �� �����ϴ�!" << endl;
        return;
    }

    // 2. (100, 100)���� �����̵� ��� (2x3)
    Mat shiftMat = Mat::eye(2, 3, CV_64F);
    shiftMat.at<double>(0, 2) = 100;
    shiftMat.at<double>(1, 2) = 100;

    // 3. �̵� ����
    Mat shifted;
    warpAffine(src, shifted, shiftMat, src.size());

    // 4. �̵��� ���� ����, ���� �߽� �������� 45�� ȸ�� ��� ����
    Point2f center(src.cols / 2.0f, src.rows / 2.0f);
    Mat rotateMat = getRotationMatrix2D(center, 45, 1.0);

    // 5. ȸ�� ����
    Mat result;
    warpAffine(shifted, result, rotateMat, src.size());

    // 6. ��� ���
    imshow("Result (Shift + Rotate)", result);
    waitKey(0);
}
