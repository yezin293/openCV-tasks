#include <iostream>
#include "CannyBasic.h"
#include "CannyCompareDemo.h"
#include "ScaleForward.h"
#include "ScaleReverse.h"
#include "ResizeDemo.h"
#include "AffineTransformDemo.h"

using namespace std;

int main() {
    while (true) {
        int choice;
        cout << "=======���� ����=====\n";// 3-4 ������ ����� ���� 
        cout << "1. Canny basic Detection\n"; //4��° ���� 
        cout << "2. Canny Edge(�߰��ǽ�: lenna, circuit,lane) n\n"; //4-1-1��° ���� 
        cout << "3.������ ��� ����Ȯ�� \n"; //4-2��° ���� 
        cout << "4.������ ��� ����Ȯ�� \n"; //4-3��° ���� 
        cout << "5. ���� ũ�� ��ȯ\n"; //4-4��° ����
        cout << "6. ���� ȸ��\n"; //4-5��° ����
        
        cout << "0. ����\n";
        cout << "���� >> ";
        cin >> choice;

        switch (choice) {
        case 1: runCannyBasicDemo(); break;
        case 2: runCannyCompareDemo(); break;
        case 3: runScaleForward(); break;
        case 4: runScaleReverse(); break;
        case 5: runResizeDemo(); break;
        case 6: runGeoTransformDemo(); break;
        default: cout << "�߸��� �����Դϴ�.\n"; break; //����ó��
        }
    }
}
