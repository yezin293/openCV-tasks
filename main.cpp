#include <iostream>
#include "GaussianBlurDemo.h"
#include "MedianBlurDemo.h"
#include "SobelEdgeDemo.h"
#include "RedCatDemo.h"
#include "SobelCircuitDemo.h"
#include "SobelRiceDemo.h"
#include "LaneDemo.h"

using namespace std;

int main() {
    while (true) {
        int choice;
        cout << "\n===== OpenCV ���� �ǽ� �޴� =====\n";
        cout << "1. Gaussian Blur\n"; // 1 ����þȽ���������
        cout << "2. Median Blur\n"; //1-1 MedianBlur ����
        cout << "3. Sobel Edge Detection\n"; //2  sobel����ũ ���� ����
        cout << "4. Circuit ���� - Sobel + ����ȭ\n";//2-1 Circuit ���� ��������
        cout << "5. Rice ���� - Sobel + ����ȭ ��\n"; //2-2 rice ���� ��������
        cout << "6. ���� �ν� ������ (Lane1)\n"; //3 �����ν�
        cout << "7. Red Cat\n";// 4 ������ ����� ���� 
        cout << "0. ����\n";
        cout << "���� >> ";
        cin >> choice;

        switch (choice) {
        case 1: runGaussianBlurDemo(); break;
        case 2: runMedianBlurDemo(); break;
        case 3: runSobelEdgeDemo(); break;
        case 4: runSobelCircuitDemo(); break;
        case 5: runSobelRiceDemo(); break;
        case 6: runLaneDemo(); break;
        case 7: runRedCatVideoDemo(); break;
        case 0: cout << "�����մϴ�!\n"; return 0;
        default: cout << "�߸��� �����Դϴ�.\n"; break; //����ó��
        }
    }
}
