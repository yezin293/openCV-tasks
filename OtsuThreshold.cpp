#include <opencv2/opencv.hpp> // OpenCV ���̺귯�� ����
#include <iostream> // ǥ�� ����� ���̺귯�� ����

using namespace cv;  // OpenCV ���ӽ����̽� ���
using namespace std; // ǥ�� ���ӽ����̽� ���

// Otsu �˰����� �̿��� �ڵ� �Ӱ谪 ����ȭ �Լ�
void runOtsuThreshold() {
    // "Lenna.jpg" �̹����� �ҷ����µ�, IMREAD_GRAYSCALE �ɼ��� ����Ͽ� �׷��̽����Ϸ� �ε�
    Mat src = imread("Lenna.jpg", IMREAD_GRAYSCALE);

    // �̹����� ���������� �ε���� �ʾ��� ��� ���� �޽��� ��� �� ����
    if (src.empty()) {
        cout << "�̹����� �ε��� �� �����ϴ�!" << endl;
        return;
    }

    // ����ȭ�� ���� ��� Mat ��ü ����
    Mat binary;

    // Otsu�� ����ȭ ����
    // threshold(�Է� ����, ��� ����, �Ӱ谪, �ִ밪, �Ӱ谪 ���� ���)
    // THRESH_OTSU �ɼ��� ����ϸ� �Ӱ谪�� �ڵ����� ������ ��
    threshold(src, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // ���� ���� ���
    imshow("Original Image", src);

    // Otsu ����ȭ�� ���� ���
    imshow("Otsu Binary Image", binary);

    //â ��ġ ���� (���� ���� ����, Otsu ����ȭ ���� ������ ��ġ)
    moveWindow("Original Image", 100, 100);   // ���� ���� â�� (100,100)�� ��ġ
    moveWindow("Otsu Binary Image", 750, 100); // ����ȭ�� ������ ������(750,100)�� ��ġ

    // ����ڰ� Ű �Է��� ������ ��� (â�� �ٷ� ������ �ʵ���)
    waitKey(0);

    // �������� �Ҵ�� �޸� ���� (OpenCV������ �ʿ� ������ �߰�)
    src.release();
    binary.release();
}
