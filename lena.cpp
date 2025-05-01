#include <opencv2/opencv.hpp>
#include "corner_harris_utils.h"

using namespace cv;
using namespace std;

void runLenaExperiment() {
    Mat src = imread("./lena.bmp");
    if (src.empty()) {
        cout << "�̹����� �ҷ��� �� �����ϴ�." << endl;
        return;
    }

    // ���� ����ó��!
    detectAndDrawHarrisCorners(src, "Lena", 6, 3, 0.04, 75, 1, "lena");
    detectAndDrawHarrisCorners(src, "Lena", 8, 3, 0.04, 70, 2, "lena");
    detectAndDrawHarrisCorners(src, "Lena", 8, 3, 0.04, 60, 3, "lena");

    waitKey(0);
    destroyAllWindows();
}
//�������� ���� �߰��ؼ� �����ϱ� 3-4�� ������ �ɵ� 