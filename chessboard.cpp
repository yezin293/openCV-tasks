#include <opencv2/opencv.hpp>
#include "corner_harris_utils.h"

using namespace cv;
using namespace std;

void runChessboardExperiment() {
    Mat src = imread("./chessboard.png");
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return;
    }

    detectAndDrawHarrisCorners(src, "Chessboard", 3, 3, 0.04, 150, 1, "chessboard");
    detectAndDrawHarrisCorners(src, "Chessboard", 5, 3, 0.04, 150, 2, "chessboard");
    detectAndDrawHarrisCorners(src, "Chessboard", 7, 3, 0.04, 150, 3, "chessboard");

    waitKey(0);
    destroyAllWindows();
}
