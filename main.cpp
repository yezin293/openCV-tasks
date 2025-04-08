#include <iostream>                      // �ܼ� ����� ���
#include "MirrorDemo.h"                 // 1. �̷��� �Լ� ����
#include "BinaryMorphologyDemo.h"       // 2. ���� �������� (ħ��, ��â)
#include "OpenCloseMorphologyDemo.h"    // 3. ����(Open), ����(Close) ����
#include "MorhpGradientDemo.h"          // 4. �������� �׷����Ʈ ����
#include "GrayMorphologyDemo.h"         // 5. �׷��� ���� ��â �� ħ��
#include "TopHatDemo.h"                 // 6. Top-hat + Otsu ����ȭ
#include "TopHatSEComparison.h"         // 7. SE ũ�� ���� �� ����
#include "WarpingDemo.h"                // 8. ���� �ְ�(����)

using namespace std;

int main() {
    while (true) {  // ���� ����: ����ڰ� 0�� �Է��� ������ �ݺ�
        int choice;
        // ����� �޴� ���
        cout << "=======���� ����=====\n";
        cout << "1. �̷��� (1��) \n";
        cout << "2. ������������ ����(2��) \n";
        cout << "3. ���� ����� ���� ����(2-2��) \n";
        cout << "4. �������� �׷����Ʈ(lena.bmp , letterj.bmp) (2-3��) \n";
        cout << "5. �׷��� ���� �������� ħ�� �� ��â(2-4��) \n";
        cout << "6. Top-hat ��ȯ �� Otsu����ȭ �� (3��) \n";
        cout << "7. Top-hat ��ȯ Structing Element(SE) ũ�� �ٲ㺸�� (3-2��) \n";
        cout << "8. ����ְ�(4��)\n";
        cout << "0. ����\n";
        cout << "���� >> ";
        cin >> choice;

        // ������ ��ȣ�� ���� �ش� �ǽ� �Լ� ȣ��
        switch (choice) {
        case 1: runMirrorDemo(); break;                 // 1�� - �̷���
        case 2: runBinaryMorphologyDemo(); break;       // 2�� - ���� ħ��/��â
        case 3: runOpenCloseMorphologyDemo(); break;    // 2-2�� - ����/����
        case 4: runMorphGradientDemo(); break;          // 2-3�� - �׷����Ʈ ����
        case 5: runGrayMorphologyDemo(); break;         // 2-4�� - �׷��� ��â/ħ��
        case 6: runTopHatDemo(); break;                 // 3�� - Top-hat + Otsu
        case 7: runTopHatSEComparison(); break;         // 3-2�� - SE ũ�� ���� ��
        case 8: runWarpingDemo(); break;                // 4�� - ���� ����
        case 0: return 0;                               // 0�� - ����
        default: cout << "�߸��� �����Դϴ�.\n"; break; // �߸��� ��ȣ ���� ó��
        }
    }
}
