#include <opencv2/opencv.hpp>
#include <iostream>
#include "ResizeDemo.h"

using namespace cv;
using namespace std;

void runResizeDemo() {
    Mat src = imread("lenna.jpg", IMREAD_COLOR);
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return;
    }

    Mat dst;
    // 4배 확대 (Nearest-Neighbor 보간법 사용)
    resize(src, dst, Size(), 4.0, 4.0, INTER_NEAREST);

    imshow("Original Image", src);
    imshow("Resized Image (4x)", dst);
    imwrite("lenna_scaled0.jpg", dst);  // 결과 저장

    waitKey(0);
    destroyAllWindows();
}
