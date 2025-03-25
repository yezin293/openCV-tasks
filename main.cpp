 #include <iostream> // 표준 입출력 라이브러리

// 각 실습의 함수 선언 (extern을 사용해 다른 .cpp 파일에서 불러옴)
extern void runBlueImage(); //실습 1: 640x480 Blue 컬러 영상 생성 함수
extern void runExtractRegion(); // 실습 2: Lenna.jpg 부분 영상 추출 및 반전 함수
extern void runThresholding(); // 실습 3: 일반 Threshold 이진화 함수
extern void runOtsuThreshold(); // 실습 3-1: Ostu 알고리즘 이진화 함수
extern void runTernaryThreshold(); // 실습 4: 삼진화 영상 처리 함수 

using namespace std; // std 네임스페이스 사용 선언

int main() {
    while (true) { //사용자가 종료하기 전까지 반복 실행
        int choice; // 사용자의 입력을 저장할 변수 

        // 메뉴 출력 
        cout << "\n=====OpenCV 실습과제 선택 =====\n";
        cout << "1. 640x480 Blue 컬러 영상 생성\n";
        cout << "2. Lenna.jpg 부분 영상 추출 및 반전\n";
        cout << "3. 일반 Threshold 이진화\n";
        cout << "4. Otsu 알고리즘 이진화\n";
        cout << "5. 삼진화 영상 처리\n";
        cout << "0. 종료\n";
        cout << "실행할 실습 번호 입력: ";
        cin >> choice; // 사용자 입력 받기 

        switch (choice) { 
        case 1: runBlueImage(); break; // 실습 1 실행
        case 2: runExtractRegion(); break; //실습 2 실행
        case 3: runThresholding(); break; //실습 3 실행
        case 4: runOtsuThreshold(); break;// 실습 3-1 실행
        case 5: runTernaryThreshold(); break; // 실습 4 실행
        case 0: cout << "프로그램 종료!\n"; return 0; // 종료 메시지 출력
        default: cout << "올바른 번호를 입력하세요!\n"; break; //잘못된 번호 입력으로 인한 예외 처리 
        }
    }
}
