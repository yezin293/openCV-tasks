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
        cout << "\n===== OpenCV 필터 실습 메뉴 =====\n";
        cout << "1. Gaussian Blur\n"; // 1 가우시안스무딩필터
        cout << "2. Median Blur\n"; //1-1 MedianBlur 필터
        cout << "3. Sobel Edge Detection\n"; //2  sobel마스크 에지 검출
        cout << "4. Circuit 영상 - Sobel + 이진화\n";//2-1 Circuit 영상 에지검출
        cout << "5. Rice 영상 - Sobel + 이진화 비교\n"; //2-2 rice 영상 에지검출
        cout << "6. 차선 인식 시퀀스 (Lane1)\n"; //3 차선인식
        cout << "7. Red Cat\n";// 4 빨간색 고양이 영상 
        cout << "0. 종료\n";
        cout << "선택 >> ";
        cin >> choice;

        switch (choice) {
        case 1: runGaussianBlurDemo(); break;
        case 2: runMedianBlurDemo(); break;
        case 3: runSobelEdgeDemo(); break;
        case 4: runSobelCircuitDemo(); break;
        case 5: runSobelRiceDemo(); break;
        case 6: runLaneDemo(); break;
        case 7: runRedCatVideoDemo(); break;
        case 0: cout << "종료합니다!\n"; return 0;
        default: cout << "잘못된 선택입니다.\n"; break; //예외처리
        }
    }
}
