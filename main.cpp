#include <iostream>
#include "model_plane.h"   // 1차 모델 기반 조명 보정 함수
#include "model_quad.h"    // 2차 모델 비교 함수
using namespace std;

int main() {
    while (true) {
        // 사용자 선택 메뉴 출력
        cout << "\n===== 밝기 보정 실험 =====" << endl;
        cout << "1. 1차 모델링만 수행 (3.1)" << endl;
        cout << "2. 1차 모델링 + 밝기 보정 (3.2)" << endl;
        cout << "3. 1차 모델 + Otsu 이진화 (3.3)" << endl;
        cout << "4. 1차 vs 2차 모델 비교 (3.4)" << endl;
        cout << "0. 종료" << endl;
        cout << "입력: ";

        int choice;
        cin >> choice;

        if (choice == 0) break; // 0 선택 시 종료

        switch (choice) {
        case 1:
            // 3.1: 배경 밝기만 모델링하여 추정
            run_model_plane("src.bmp", 1);
            break;
        case 2:
            // 3.2: 배경 모델을 이용한 차영상(조명 보정) 계산
            run_model_plane("src.bmp", 2);
            break;
        case 3:
            // 3.3: 보정된 차영상에 대해 Otsu 이진화 수행
            run_model_plane("src.bmp", 3);
            break;
        case 4:
            // 3.4: book.png에 대해 1차/2차 모델 비교 및 이진화 결과 시각화
            run_model_quad("book.png");
            break;
        default:
            // 그 외 입력 처리
            cout << "잘못된 입력입니다." << endl;
        }
    }
    return 0;
}
