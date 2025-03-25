 #include <iostream> // ǥ�� ����� ���̺귯��

// �� �ǽ��� �Լ� ���� (extern�� ����� �ٸ� .cpp ���Ͽ��� �ҷ���)
extern void runBlueImage(); //�ǽ� 1: 640x480 Blue �÷� ���� ���� �Լ�
extern void runExtractRegion(); // �ǽ� 2: Lenna.jpg �κ� ���� ���� �� ���� �Լ�
extern void runThresholding(); // �ǽ� 3: �Ϲ� Threshold ����ȭ �Լ�
extern void runOtsuThreshold(); // �ǽ� 3-1: Ostu �˰��� ����ȭ �Լ�
extern void runTernaryThreshold(); // �ǽ� 4: ����ȭ ���� ó�� �Լ� 

using namespace std; // std ���ӽ����̽� ��� ����

int main() {
    while (true) { //����ڰ� �����ϱ� ������ �ݺ� ����
        int choice; // ������� �Է��� ������ ���� 

        // �޴� ��� 
        cout << "\n=====OpenCV �ǽ����� ���� =====\n";
        cout << "1. 640x480 Blue �÷� ���� ����\n";
        cout << "2. Lenna.jpg �κ� ���� ���� �� ����\n";
        cout << "3. �Ϲ� Threshold ����ȭ\n";
        cout << "4. Otsu �˰��� ����ȭ\n";
        cout << "5. ����ȭ ���� ó��\n";
        cout << "0. ����\n";
        cout << "������ �ǽ� ��ȣ �Է�: ";
        cin >> choice; // ����� �Է� �ޱ� 

        switch (choice) { 
        case 1: runBlueImage(); break; // �ǽ� 1 ����
        case 2: runExtractRegion(); break; //�ǽ� 2 ����
        case 3: runThresholding(); break; //�ǽ� 3 ����
        case 4: runOtsuThreshold(); break;// �ǽ� 3-1 ����
        case 5: runTernaryThreshold(); break; // �ǽ� 4 ����
        case 0: cout << "���α׷� ����!\n"; return 0; // ���� �޽��� ���
        default: cout << "�ùٸ� ��ȣ�� �Է��ϼ���!\n"; break; //�߸��� ��ȣ �Է����� ���� ���� ó�� 
        }
    }
}
