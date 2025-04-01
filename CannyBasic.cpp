#include <opencv2/opencv.hpp>
#include <iostream>
#include "CannyBasic.h"

using namespace cv;
using namespace std;

// 기본 Canny 에지 검출 함수
void runCannyBasicDemo() {
    Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE); // 기본 파일명 그대로 사용


    if (src.empty()) {
        cout << "영상을 읽을 수 없습니다!" << endl;
        return;
    }

    Mat canny = src.clone();

    // Canny 에지 검출 (기본값)
    Canny(src, canny, 150, 200, 3); // aperture_size = 3

    imshow("Original Image", src);
    imshow("Canny Edge (150-200)", canny);
    waitKey(0);
    destroyAllWindows();
}
