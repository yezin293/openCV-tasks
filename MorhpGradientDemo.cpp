#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

// �������� �׷����Ʈ�� �̿��� �ܰ��� ���� �Լ�
void runMorphGradientDemo() {
    // ó���� �̹��� ���� ����Ʈ
    string files[] = { "lena.bmp", "letterj.png" };

    for (int i = 0; i < 2; ++i) {
        Mat src = imread(files[i], IMREAD_GRAYSCALE);
        if (src.empty()) {
            cout << files[i] << " �̹����� �ҷ��� �� �����ϴ�!" << endl;
            continue;
        }

        // 5x5 �簢�� ���� ��� ����
        Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));

        // �������� �׷����Ʈ ����
        Mat gradient;
        morphologyEx(src, gradient, MORPH_GRADIENT, element);

        // ���
        string winOriginal = "Original - " + files[i];
        string winResult = "Morph Gradient - " + files[i];

        imshow(winOriginal, src);
        moveWindow(winOriginal, 100 + 600 * i, 100);

        imshow(winResult, gradient);
        moveWindow(winResult, 100 + 600 * i, 400);
    }

    waitKey(0);
    destroyAllWindows();
}
