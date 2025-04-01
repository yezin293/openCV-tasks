#include <opencv2/opencv.hpp>
#include <iostream>
#include "ScaleReverse.h"

using namespace cv;
using namespace std;

void runScaleReverse() {
    Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return;
    }

    Mat dst = Mat::zeros(Size(src.cols * 2, src.rows * 2), src.type());

    for (int y = 0; y < dst.rows; y++) {
        for (int x = 0; x < dst.cols; x++) {
            int srcX = static_cast<int>(x / 2.0);
            int srcY = static_cast<int>(y / 2.0);
            dst.at<uchar>(y, x) = src.at<uchar>(srcY, srcX);
        }
    }

    imshow("Original Image", src);
    imshow("Reverse Scaled Image", dst);
    waitKey(0);
}
