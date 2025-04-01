#include <opencv2/opencv.hpp>
#include <iostream>
#include "ResizeDemo.h"

using namespace cv;
using namespace std;

void runResizeDemo() {
    Mat src = imread("lenna.jpg", IMREAD_COLOR);
    if (src.empty()) {
        cout << "�̹����� �ҷ��� �� �����ϴ�." << endl;
        return;
    }

    Mat dst;
    // 4�� Ȯ�� (Nearest-Neighbor ������ ���)
    resize(src, dst, Size(), 4.0, 4.0, INTER_NEAREST);

    imshow("Original Image", src);
    imshow("Resized Image (4x)", dst);
    imwrite("lenna_scaled0.jpg", dst);  // ��� ����

    waitKey(0);
    destroyAllWindows();
}
