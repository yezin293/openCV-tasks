#include <opencv2/opencv.hpp> // OpenCV ���̺귯�� ����
#include <iostream> // ǥ�� ����� ���̺귯�� ����

using namespace cv;  // OpenCV ���ӽ����̽� ���
using namespace std; // ǥ�� ���ӽ����̽� ���

// ���� 2�� �κ� ������ ���������� �����ϰ� ���� ó�� �� ������ â�� ���÷����ϴ� �Լ�
void runExtractRegion() {
    // ���� �̹��� �ε�
    Mat src = imread("Lenna.jpg");

    // �̹����� ���������� �ε���� �ʾ��� ��� ���� �޽��� ��� �� ����
    if (src.empty()) {
        cout << "�̹����� �ε��� �� �����ϴ�!" << endl;
        return;
    }

    // ���� ����(ROI) ���� (���� ��ǥ: (200,200), ũ��: 100x100)
    Rect roi(200, 200, 100, 100);

    // �������� �κ� ���� ���� (clone()�� ����� ������ ������ ����)
    Mat region = src(roi).clone();

    // �κ� ���� ���� ó��
    bitwise_not(region, region);

    // ���� ���� ���
    imshow("Original Image", src);

    // ������ �κ� ���� ��� (������ â���� ǥ��)
    imshow("Inverted Region", region);

    // ����ڰ� Ű �Է��� ������ ��� (â�� ������ �ʵ���)
    waitKey(0);
}
