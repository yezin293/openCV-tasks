#include "corner_harris_utils.h"

void detectAndDrawHarrisCorners(const Mat& src, const string& windowName,
    int blockSize, int ksize, double k, int threshold,
    int experimentNumber, const string& savePrefix) {
    Mat gray;
    if (src.channels() == 3) {
        cvtColor(src, gray, COLOR_BGR2GRAY);
    }
    else {
        gray = src.clone();
    }

    Mat dst, dst_norm, dst_norm_scaled;
    dst = Mat::zeros(src.size(), CV_32FC1);

    // Harris �ڳ� ����
    cornerHarris(gray, dst, blockSize, ksize, k, BORDER_DEFAULT);

    // Normalize
    normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    convertScaleAbs(dst_norm, dst_norm_scaled);

    // Strength map �����ֱ�
    string normWindowName = windowName + " - StrengthMap " + to_string(experimentNumber);
    imshow(normWindowName, dst_norm_scaled);

    // �ڳ��� ǥ��
    Mat resultImage = src.clone();
    // �ڳ��� ǥ��
    for (int j = 0; j < dst_norm.rows; j++) {
        for (int i = 0; i < dst_norm.cols; i++) {
            if ((int)dst_norm.at<float>(j, i) > threshold) {
                circle(resultImage, Point(i, j), 0, Scalar(0, 0, 255), -1, 8, 0);

            }
        }
    }

    // ��� �����ֱ�
    string expWindowName = windowName + " - Experiment " + to_string(experimentNumber);
    imshow(expWindowName, resultImage);

    // ��� ����
    string filename = savePrefix + "_result_" + to_string(experimentNumber) + ".png";
    imwrite(filename, resultImage);
}
