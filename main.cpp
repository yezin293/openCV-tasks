#include <iostream>
#include "model_plane.h"   // 1�� �� ��� ���� ���� �Լ�
#include "model_quad.h"    // 2�� �� �� �Լ�
using namespace std;

int main() {
    while (true) {
        // ����� ���� �޴� ���
        cout << "\n===== ��� ���� ���� =====" << endl;
        cout << "1. 1�� �𵨸��� ���� (3.1)" << endl;
        cout << "2. 1�� �𵨸� + ��� ���� (3.2)" << endl;
        cout << "3. 1�� �� + Otsu ����ȭ (3.3)" << endl;
        cout << "4. 1�� vs 2�� �� �� (3.4)" << endl;
        cout << "0. ����" << endl;
        cout << "�Է�: ";

        int choice;
        cin >> choice;

        if (choice == 0) break; // 0 ���� �� ����

        switch (choice) {
        case 1:
            // 3.1: ��� ��⸸ �𵨸��Ͽ� ����
            run_model_plane("src.bmp", 1);
            break;
        case 2:
            // 3.2: ��� ���� �̿��� ������(���� ����) ���
            run_model_plane("src.bmp", 2);
            break;
        case 3:
            // 3.3: ������ ������ ���� Otsu ����ȭ ����
            run_model_plane("src.bmp", 3);
            break;
        case 4:
            // 3.4: book.png�� ���� 1��/2�� �� �� �� ����ȭ ��� �ð�ȭ
            run_model_quad("book.png");
            break;
        default:
            // �� �� �Է� ó��
            cout << "�߸��� �Է��Դϴ�." << endl;
        }
    }
    return 0;
}
