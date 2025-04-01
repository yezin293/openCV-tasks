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
        cout << "=======과제 선택=====\n";// 3-4 빨간색 고양이 영상 
        cout << "1. Canny basic Detection\n"; //4번째 과제 
        cout << "2. Canny Edge(추가실습: lenna, circuit,lane) n\n"; //4-1-1번째 과제 
        cout << "3.순방향 사상 영상확대 \n"; //4-2번째 과제 
        cout << "4.역방향 사상 영상확대 \n"; //4-3번째 과제 
        cout << "5. 영상 크기 변환\n"; //4-4번째 과제
        cout << "6. 영상 회전\n"; //4-5번째 과제
        
        cout << "0. 종료\n";
        cout << "선택 >> ";
        cin >> choice;

        switch (choice) {
        case 1: runCannyBasicDemo(); break;
        case 2: runCannyCompareDemo(); break;
        case 3: runScaleForward(); break;
        case 4: runScaleReverse(); break;
        case 5: runResizeDemo(); break;
        case 6: runGeoTransformDemo(); break;
        default: cout << "잘못된 선택입니다.\n"; break; //예외처리
        }
    }
}
