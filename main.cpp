#include <iostream>

// �Լ� ����
void runChessboardExperiment();
void runFigureExperiment();
void runLenaExperiment();

using namespace std;

int main() {
    while (true) {
        cout << "===== Harris Corner Detection ���� =====" << endl;
        cout << "1. Chessboard" << endl;
        cout << "2. Figure" << endl;
        cout << "3. Lena" << endl;
        cout << "0. ����" << endl;
        cout << "������ ��ȣ�� �Է��ϼ���: ";

        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }

        switch (choice) {
        case 1:
            runChessboardExperiment();
            break;
        case 2:
            runFigureExperiment();
            break;
        case 3:
            runLenaExperiment();
            break;
        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
            break;
        }
    }

    return 0;
}
