#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

// ������ ����ȭ�� ���� rice �� book2 �̹������� ��ü(��, ����)�� �и��ϴ� �Լ�
void runAdaptiveSegmentationDemo() {
    // ó���� �̹��� ���� ����Ʈ
    vector<string> imageFiles = { "rice.bmp", "book2.png" };

    // �� �̹����� ���� �ݺ� ����
    for (const string& filename : imageFiles) {
        // �̹����� �׷��̽����Ϸ� �ҷ���
        Mat src = imread(filename, IMREAD_GRAYSCALE);
        if (src.empty()) {
            cout << filename << " �ҷ����� ����!" << endl;
            continue;
        }

        Mat blurred, preprocessed;
        // median blur�� ���� ������ ���� (Ư�� salt-and-pepper noise�� ȿ����)
        medianBlur(src, blurred, 5);

        // ������׷� ��Ȱȭ�� ���� ��� ��� ���� (�� �ѷ��� ����ȭ�� ����)
        equalizeHist(blurred, preprocessed);

        Mat meanResult, gaussianResult;
        int blockSize = 25;  // ��� ũ�� (25x25 �ֺ� �̿� ������ �������� �Ӱ谪 ���)
        int C = 5;           // ��� �Ǵ� ������տ��� ���ִ� ���

        // ��� ��� ������ �Ӱ�ȭ
        adaptiveThreshold(preprocessed, meanResult, 255,
            ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSize, C);

        // ����þ� ��� ������ �Ӱ�ȭ
        adaptiveThreshold(preprocessed, gaussianResult, 255,
            ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blockSize, C);

        // ���� �� ��� ���� ���
        imshow("Original - " + filename, src);
        imshow("Adaptive Mean - " + filename, meanResult);
        imshow("Adaptive Gaussian - " + filename, gaussianResult);
    }

    // ��� â�� �����ϴٰ� Ű �Է� �� ����
    waitKey(0);
    destroyAllWindows();
}
