#include <opencv2/opencv.hpp>  //OpenCV ���̺귯�� ����
#include <iostream> // ǥ�� ����� ���̺귯�� ����

using namespace cv; //OpenCV ���� �����̽� ��� 
using namespace std; // ǥ�� ���� �����̽� ��� 

//���� 1���� ���� �Լ� 
void runBlueImage() {
    //640x480 ũ���� 3ä�� �÷� ���� Mat��ü ����
    //Scalar(255,0,0) -> �Ķ���
    Mat blueImage(480, 640, CV_8UC3, Scalar(255, 0, 0));
    // ������ ������ ȭ�鿡 ��� 
    imshow("Blue Image", blueImage);
    //����� �Է� Ű ��� 
    waitKey(0);
}
