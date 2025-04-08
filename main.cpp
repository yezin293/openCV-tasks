#include <iostream>                      // 콘솔 입출력 사용
#include "MirrorDemo.h"                 // 1. 미러링 함수 선언
#include "BinaryMorphologyDemo.h"       // 2. 이진 모폴로지 (침식, 팽창)
#include "OpenCloseMorphologyDemo.h"    // 3. 열림(Open), 닫힘(Close) 연산
#include "MorhpGradientDemo.h"          // 4. 형태학적 그래디언트 연산
#include "GrayMorphologyDemo.h"         // 5. 그레이 영상 팽창 및 침식
#include "TopHatDemo.h"                 // 6. Top-hat + Otsu 이진화
#include "TopHatSEComparison.h"         // 7. SE 크기 변경 비교 실험
#include "WarpingDemo.h"                // 8. 영상 왜곡(워핑)

using namespace std;

int main() {
    while (true) {  // 무한 루프: 사용자가 0을 입력할 때까지 반복
        int choice;
        // 사용자 메뉴 출력
        cout << "=======과제 선택=====\n";
        cout << "1. 미러링 (1번) \n";
        cout << "2. 이진모폴로지 연산(2번) \n";
        cout << "3. 열림 연산과 닫힘 연산(2-2번) \n";
        cout << "4. 형태학적 그래디언트(lena.bmp , letterj.bmp) (2-3번) \n";
        cout << "5. 그레이 영상 형태학적 침식 및 팽창(2-4번) \n";
        cout << "6. Top-hat 변환 및 Otsu이진화 비교 (3번) \n";
        cout << "7. Top-hat 변환 Structing Element(SE) 크기 바꿔보기 (3-2번) \n";
        cout << "8. 영상왜곡(4번)\n";
        cout << "0. 종료\n";
        cout << "선택 >> ";
        cin >> choice;

        // 선택한 번호에 따라 해당 실습 함수 호출
        switch (choice) {
        case 1: runMirrorDemo(); break;                 // 1번 - 미러링
        case 2: runBinaryMorphologyDemo(); break;       // 2번 - 이진 침식/팽창
        case 3: runOpenCloseMorphologyDemo(); break;    // 2-2번 - 열림/닫힘
        case 4: runMorphGradientDemo(); break;          // 2-3번 - 그래디언트 연산
        case 5: runGrayMorphologyDemo(); break;         // 2-4번 - 그레이 팽창/침식
        case 6: runTopHatDemo(); break;                 // 3번 - Top-hat + Otsu
        case 7: runTopHatSEComparison(); break;         // 3-2번 - SE 크기 변경 비교
        case 8: runWarpingDemo(); break;                // 4번 - 영상 워핑
        case 0: return 0;                               // 0번 - 종료
        default: cout << "잘못된 선택입니다.\n"; break; // 잘못된 번호 예외 처리
        }
    }
}
