#include <iostream>

// 함수 선언
void runChessboardExperiment();
void runFigureExperiment();
void runLenaExperiment();

using namespace std;

int main() {
    while (true) {
        cout << "===== Harris Corner Detection 실험 =====" << endl;
        cout << "1. Chessboard" << endl;
        cout << "2. Figure" << endl;
        cout << "3. Lena" << endl;
        cout << "0. 종료" << endl;
        cout << "실행할 번호를 입력하세요: ";

        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "프로그램을 종료합니다." << endl;
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
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            break;
        }
    }

    return 0;
}
