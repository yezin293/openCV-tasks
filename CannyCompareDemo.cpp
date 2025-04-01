#include <opencv2/opencv.hpp>
#include <iostream>
#include "CannyCompareDemo.h"

using namespace cv;
using namespace std;

void runCannyCompareDemo() {
    vector<string> imageNames = { "lenna.jpg", "circuit.bmp", "./Lane1/00001.jpg" };
    vector<string> titles = { "Lenna", "Circuit", "Lane1 Frame1" };

    int imgWidth = 300;  // 더 작게 축소
    int gapX = 330;      // 창 가로 간격
    int gapY = 250;      // 창 세로 간격

    for (int i = 0; i < imageNames.size(); i++) {
        Mat src = imread(imageNames[i], IMREAD_GRAYSCALE);
        if (src.empty()) {
            cout << "영상을 불러올 수 없습니다: " << imageNames[i] << endl;
            continue;
        }

        float scale = imgWidth / (float)src.cols;
        Size newSize(imgWidth, (int)(src.rows * scale));

        Mat edge1, edge2, srcResized, edge1Resized, edge2Resized;

        resize(src, srcResized, newSize);
        Canny(src, edge1, 100, 150, 3);
        Canny(src, edge2, 180, 220, 3);
        resize(edge1, edge1Resized, newSize);
        resize(edge2, edge2Resized, newSize);

        int row = i; // 각 영상마다 한 줄씩 출력

        imshow(titles[i] + " - Original", srcResized);
        moveWindow(titles[i] + " - Original", 50, row * gapY);

        imshow(titles[i] + " - Canny 100-150", edge1Resized);
        moveWindow(titles[i] + " - Canny 100-150", 50 + gapX, row * gapY);

        imshow(titles[i] + " - Canny 180-220", edge2Resized);
        moveWindow(titles[i] + " - Canny 180-220", 50 + 2 * gapX, row * gapY);
    }

    waitKey(0);
    destroyAllWindows();
}
