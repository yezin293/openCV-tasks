#include "utils.h"
using namespace cv;

// ��� ���󿡼� ���� ������ �� ������ ��� (���� ���� ����)
Mat compute_difference_inverse(const Mat& original, const Mat& background) {
    CV_Assert(original.size() == background.size()); // ũ�� ��ġ Ȯ��
    Mat corrected(original.rows, original.cols, CV_8UC1); // ��� ���� ����

    for (int y = 0; y < original.rows; ++y) {
        for (int x = 0; x < original.cols; ++x) {
            int orig = static_cast<int>(original.at<uchar>(y, x));    // ���� ��Ⱚ
            int bg = static_cast<int>(background.at<uchar>(y, x));    // ��� ��Ⱚ
            int diff = bg - orig;                                     // ��� - ����

            corrected.at<uchar>(y, x) = saturate_cast<uchar>(diff);   // ��� ���� (0~255�� Ŭ����)
        }
    }

    return corrected;
}
