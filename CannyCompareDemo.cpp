#include <opencv2/opencv.hpp>
#include <iostream>
#include "CannyCompareDemo.h"

using namespace cv;
using namespace std;

void runCannyCompareDemo() {
    vector<string> imageNames = { "lenna.jpg", "circuit.bmp", "./Lane1/00001.jpg" };
    vector<string> titles = { "Lenna", "Circuit", "Lane1 Frame1" };

    int imgWidth = 300;  // �� �۰� ���
    int gapX = 330;      // â ���� ����
    int gapY = 250;      // â ���� ����

    for (int i = 0; i < imageNames.size(); i++) {
        Mat src = imread(imageNames[i], IMREAD_GRAYSCALE);
        if (src.empty()) {
            cout << "������ �ҷ��� �� �����ϴ�: " << imageNames[i] << endl;
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

        int row = i; // �� ���󸶴� �� �پ� ���

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
