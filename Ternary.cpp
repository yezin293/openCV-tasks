#include <opencv2/opencv.hpp> // OpenCV ���̺귯�� ����
#include <iostream> // ǥ�� ����� ���̺귯�� ����

using namespace cv;  // OpenCV ���ӽ����̽� ���
using namespace std; // ǥ�� ���ӽ����̽� ���

// ����ȭ(Ternary Threshold) ó�� �Լ� (���� ���� �Բ� ���)
void runTernaryThreshold() {
    // "Lenna.jpg" �̹����� �ҷ����µ�, IMREAD_GRAYSCALE �ɼ��� ����Ͽ� �׷��̽����Ϸ� �ε�
    Mat src = imread("Lenna.jpg", IMREAD_GRAYSCALE);

    // �̹����� ���������� �ε���� �ʾ��� ��� ���� �޽��� ��� �� ����
    if (src.empty()) {
        cout << "�̹����� �ε��� �� �����ϴ�!" << endl;
        return;
    }

    // ���� �̹����� �����Ͽ� ����ȭ ����� ������ Mat ��ü ����
    Mat ternary = src.clone();

    // ��� �ȼ��� ��ȸ�ϸ鼭 ����ȭ ����
    for (int y = 0; y < src.rows; y++) {  // ��(���� ����) ��ȸ
        for (int x = 0; x < src.cols; x++) {  // ��(���� ����) ��ȸ
            uchar pixel = src.at<uchar>(y, x); // ���� �ȼ� ��� �� ��������

            // ����ȭ ����
            if (pixel < 85)
                ternary.at<uchar>(y, x) = 0;      // ��ο� ����(0~84)�� ������(0)
            else if (pixel < 170)
                ternary.at<uchar>(y, x) = 128;    // �߰� ��� ����(85~169)�� ȸ��(128)
            else
                ternary.at<uchar>(y, x) = 255;    // ���� ����(170~255)�� ���(255)
        }
    }

    // ���� ���� ���
    imshow("Original Image", src);

    // ����ȭ�� ���� ���
    imshow("Ternary Image", ternary);

    //â ��ġ ���� (���� ���� ����, ����ȭ�� ���� ������ ��ġ)
    moveWindow("Original Image", 100, 100);   // ���� ���� â�� (100,100)�� ��ġ
    moveWindow("Ternary Image", 750, 100);   // ����ȭ�� ������ ������(750,100)�� ��ġ

    // ����ڰ� Ű �Է��� ������ ��� (â�� �ٷ� ������ �ʵ���)
    waitKey(0);

    // �������� �Ҵ�� �޸� ���� (OpenCV������ �ʿ� ������ �߰�)
    src.release();
    ternary.release();
}
