#include <opencv2/opencv.hpp>
#include "corner_harris_utils.h"

using namespace cv;
using namespace std;

void runFigureExperiment() {
    Mat src = imread("./figure.bmp");
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return;
    }

    // 둥근 사각형까지 잘 잡히게!
    detectAndDrawHarrisCorners(src, "Figure", 3, 3, 0.04, 80, 1, "figure");
    detectAndDrawHarrisCorners(src, "Figure", 5, 3, 0.04, 50, 2, "figure");
    detectAndDrawHarrisCorners(src, "Figure", 7, 3, 0.04, 40, 3, "figure");

    waitKey(0);
    destroyAllWindows();
}
