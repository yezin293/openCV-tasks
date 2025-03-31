#include <opencv2/opencv.hpp>   // OpenCV ���
#include <iostream>             // ǥ�� �����
#include "RedCatDemo.h"         // �Լ� ���� ���

using namespace cv;             // OpenCV ���ӽ����̽�
using namespace std;            // ǥ�� ���ӽ����̽�

// ���� ���͸� ������ ���� ���� �Լ�
void runRedCatVideoDemo() {
    // Cat.mp4 ������ ����
    VideoCapture cap("Cat.mp4");

    // ���� ���⿡ �������� ��� �޽��� ��� �� ����
    if (!cap.isOpened()) {
        cout << "Cat.mp4 ������ �� �� �����ϴ�!" << endl;
        return;
    }

    // ���� ���� ��������
    int width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));   // ���� �ػ�
    int height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT)); // ���� �ػ�
    int fps = static_cast<int>(cap.get(CAP_PROP_FPS));             // ������ �ӵ�

    // VideoWriter ��ü ���� (RedCat.avi�� ����)
    VideoWriter writer("RedCat.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'),
        fps, Size(width, height));

    // ���� ���� ���� ���� �� �޽��� ��� �� ����
    if (!writer.isOpened()) {
        cout << "��� ������ ������ �� �����ϴ�!" << endl;
        return;
    }

    Mat frame, modified; // ���� �����Ӱ� ������ ������

    // ������ ������ �ݺ� ó��
    while (true) {
        cap >> frame;              // ���� ������ �б�
        if (frame.empty()) break;  // ���� ���̸� ����

        modified = frame.clone();  // ���� ���� �� ������

        // ��� �ȼ��� ���� ������ ä��(R)�� 50 ����
        for (int y = 0; y < modified.rows; y++) {
            for (int x = 0; x < modified.cols; x++) {
                Vec3b& pixel = modified.at<Vec3b>(y, x); // �ȼ� ���� (BGR)
                pixel[2] = min(255, pixel[2] + 50);      // R ä�θ� ���� (�ִ� 255)
            }
        }

        imshow("RedCat Video", modified); // ȭ�鿡 ���
        writer.write(modified);           // ����

        if (waitKey(30) == 27) break; // ESC Ű ������ ���� ����
    }

    // �ڿ� ����
    cap.release();
    writer.release();
    destroyAllWindows();
}
