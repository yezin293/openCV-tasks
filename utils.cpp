#include "utils.h"
using namespace cv;

// 배경 영상에서 원본 영상을 뺀 차영상 계산 (조명 보정 목적)
Mat compute_difference_inverse(const Mat& original, const Mat& background) {
    CV_Assert(original.size() == background.size()); // 크기 일치 확인
    Mat corrected(original.rows, original.cols, CV_8UC1); // 결과 영상 생성

    for (int y = 0; y < original.rows; ++y) {
        for (int x = 0; x < original.cols; ++x) {
            int orig = static_cast<int>(original.at<uchar>(y, x));    // 원본 밝기값
            int bg = static_cast<int>(background.at<uchar>(y, x));    // 배경 밝기값
            int diff = bg - orig;                                     // 배경 - 원본

            corrected.at<uchar>(y, x) = saturate_cast<uchar>(diff);   // 결과 저장 (0~255로 클리핑)
        }
    }

    return corrected;
}
