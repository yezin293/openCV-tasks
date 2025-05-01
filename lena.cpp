#include <opencv2/opencv.hpp>
#include "corner_harris_utils.h"

using namespace cv;
using namespace std;

void runLenaExperiment() {
    Mat src = imread("./lena.bmp");
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return;
    }

    // 과제 예시처럼!
    detectAndDrawHarrisCorners(src, "Lena", 6, 3, 0.04, 75, 1, "lena");
    detectAndDrawHarrisCorners(src, "Lena", 8, 3, 0.04, 70, 2, "lena");
    detectAndDrawHarrisCorners(src, "Lena", 8, 3, 0.04, 60, 3, "lena");

    waitKey(0);
    destroyAllWindows();
}
//여러가지 샘플 추가해서 제출하기 3-4개 정도면 될듯 