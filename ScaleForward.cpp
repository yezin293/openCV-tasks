#include <opencv2/opencv.hpp>
#include <iostream>
#include "ScaleForward.h"

using namespace cv;
using namespace std;

void runScaleForward() {
    Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return;
    }

    Mat dst = Mat::zeros(Size(src.cols * 2, src.rows * 2), src.type());

    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            int newX = x * 2;
            int newY = y * 2;
            dst.at<uchar>(newY, newX) = src.at<uchar>(y, x);
        }
    }

    imshow("Original Image", src);
    imshow("Forward Scaled Image", dst);
    waitKey(0);
}
