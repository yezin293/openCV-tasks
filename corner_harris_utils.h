#ifndef CORNER_HARRIS_UTILS_H
#define CORNER_HARRIS_UTILS_H

#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

void detectAndDrawHarrisCorners(const Mat& src, const string& windowName,
    int blockSize, int ksize, double k, int threshold,
    int experimentNumber, const string& savePrefix);

#endif // CORNER_HARRIS_UTILS_H
