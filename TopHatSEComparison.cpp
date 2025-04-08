#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void runTopHatSEComparison() {
    Mat src = imread("rice.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다!" << endl;
        return;
    }

    imshow("Original Image", src);
    moveWindow("Original Image", 100, 100);

    vector<int> seSizes = { 3, 7, 15, 45 };

    for (int size : seSizes) {
        // Structuring Element 생성
        Mat se = getStructuringElement(MORPH_RECT, Size(size, size));

        // Top-hat 연산
        Mat opened;
        morphologyEx(src, opened, MORPH_OPEN, se);
        Mat tophat = src - opened;

        // Otsu 이진화
        Mat binaryTophat;
        threshold(tophat, binaryTophat, 0, 255, THRESH_BINARY | THRESH_OTSU);

        // 결과 출력
        string winName = "SE Size " + to_string(size);
        imshow(winName, binaryTophat);
        moveWindow(winName, 100 + size * 10, 150 + size * 5);
    }

    waitKey(0);
    destroyAllWindows();
}
