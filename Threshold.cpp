#include <opencv2/opencv.hpp> // OpenCV ���̺귯�� ����
#include <iostream> // ǥ�� ����� ���̺귯�� ����

using namespace cv;  // OpenCV ���ӽ����̽� ���
using namespace std; // ǥ�� ���ӽ����̽� ���

// �Ϲ� Threshold ����ȭ �Լ� (���� ���� �Բ� ���)
void runThresholding() {
    // "Lenna.jpg" �̹����� �ҷ����µ�, IMREAD_GRAYSCALE �ɼ��� ����Ͽ� �׷��̽����Ϸ� �ε�
    Mat src = imread("Lenna.jpg", IMREAD_GRAYSCALE);

    // �̹����� ���������� �ε���� �ʾ��� ��� ���� �޽��� ��� �� ����
    if (src.empty()) {
        cout << "�̹����� �ε��� �� �����ϴ�!" << endl;
        return;
    }

    // ����ȭ�� ���� ��� Mat ��ü ����
    Mat binary;

    // threshold() �Լ��� ����Ͽ� ����ȭ ����
    // threshold(�Է� ����, ��� ����, �Ӱ谪, �ִ밪, �Ӱ谪 ���� ���)
    // �� �Ӱ谪 100�� ��������:
    //    - 100 �̻��̸� 255(���)
    //    - 100 ���ϸ� 0(������)���� ��ȯ (THRESH_BINARY ����)
    threshold(src, binary, 100, 255, THRESH_BINARY);

    // ���� ���� ���
    imshow("Original Image", src);

    // ����ȭ�� ���� ���
    imshow("Binary Image", binary);

    //â ��ġ ���� (���� ���� ����, ����ȭ�� ���� ������ ��ġ)
    moveWindow("Original Image", 100, 100);  // ���� ���� â�� (100,100)�� ��ġ
    moveWindow("Binary Image", 750, 100);   // ����ȭ�� ������ ������(750,100)�� ��ġ

    // ����ڰ� Ű �Է��� ������ ��� (â�� �ٷ� ������ �ʵ���)
    waitKey(0);

    // �������� �Ҵ�� �޸� ���� (OpenCV������ �ʿ� ������ �߰�)
    src.release();
    binary.release();
}
