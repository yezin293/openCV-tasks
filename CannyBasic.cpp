#include <opencv2/opencv.hpp>
#include <iostream>
#include "CannyBasic.h"

using namespace cv;
using namespace std;

// �⺻ Canny ���� ���� �Լ�
void runCannyBasicDemo() {
    Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE); // �⺻ ���ϸ� �״�� ���


    if (src.empty()) {
        cout << "������ ���� �� �����ϴ�!" << endl;
        return;
    }

    Mat canny = src.clone();

    // Canny ���� ���� (�⺻��)
    Canny(src, canny, 150, 200, 3); // aperture_size = 3

    imshow("Original Image", src);
    imshow("Canny Edge (150-200)", canny);
    waitKey(0);
    destroyAllWindows();
}
