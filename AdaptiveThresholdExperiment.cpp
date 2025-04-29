#include <opencv2/opencv.hpp>
#include <iostream>
#include "AdaptiveThresholdExperiment.h"

using namespace cv;
using namespace std;

// ������ ����ȭ�� blockSize�� ���(Mean, Gaussian)�� ���� ��� �� ���� �Լ�
void runAdaptiveThresholdExperiment() {
    // �Է� �̹���(book1.jpg)�� �׷��̽����Ϸ� �ҷ�����
    Mat src = imread("book1.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "book1.jpg �̹����� �ҷ��� �� �����ϴ�!" << endl;
        return;
    }

    Mat img;
    // median blur�� �����Ͽ� ������ ����
    medianBlur(src, img, 5);

    // ���迡 ����� �پ��� blockSize ���� (Ȧ������ ��)
    vector<int> blockSizes = { 31, 45, 61 };
    int C = 2;  // �Ӱ谪 ��� �� ���ִ� �����
    int xOffset = 100, yOffset = 100; // â ��ġ ���� ��ǥ
    int colGap = 350, rowGap = 300;   // â ���� ����

    // �� blockSize�� ���� adaptiveThreshold ����
    for (int i = 0; i < blockSizes.size(); i++) {
        int blockSize = blockSizes[i];

        Mat meanResult, gaussianResult;

        // ��� ��� ����ȭ
        adaptiveThreshold(img, meanResult, 255,
            ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSize, C);

        // ����þ� ��� ����ȭ
        adaptiveThreshold(img, gaussianResult, 255,
            ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blockSize, C);

        // ��� �̹����� ���� ����
        string meanTitle = "Mean - blockSize " + to_string(blockSize);
        string gaussTitle = "Gaussian - blockSize " + to_string(blockSize);

        // ��� ���� ���
        imshow(meanTitle, meanResult);
        imshow(gaussTitle, gaussianResult);

        // â�� ȭ��� �����Ͽ� �񱳰� �����ϵ��� ��ġ
        int row = i / 2;
        int col = i % 2;
        moveWindow(meanTitle, xOffset + col * colGap, yOffset + row * rowGap);
        moveWindow(gaussTitle, xOffset + col * colGap + 150, yOffset + row * rowGap); // ���� ���������� ���
    }

    // ���� ����(������ ���ŵ� ����) ���
    imshow("Original (Median Blurred)", img);
    moveWindow("Original (Median Blurred)", xOffset + 2 * colGap, yOffset + rowGap);

    // Ű �Է� �ñ��� ��� �� ��� â �ݱ�
    waitKey(0);
    destroyAllWindows();
}
