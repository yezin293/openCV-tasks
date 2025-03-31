#include <opencv2/opencv.hpp>     // OpenCV 영상 처리 헤더
#include <iostream>               // 표준 입출력
#include "MedianBlurDemo.h"       // MedianBlur 함수 선언 헤더

using namespace cv;               // OpenCV 네임스페이스
using namespace std;              // 표준 네임스페이스

// MedianBlur 실습 함수 정의
void runMedianBlurDemo() {
    // 컬러 이미지 로드 (lenna.jpg 사용)
    Mat src = imread("lenna.jpg", IMREAD_COLOR);

    // 이미지 로드 실패 시 오류 메시지 출력 후 종료
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다!" << endl;
        return;
    }

    Mat dst; // 결과 이미지 저장 변수

    int mode;
    // 사용자에게 모드 선택 받기
    cout << "\n[MedianBlur 데모 모드 선택]\n";
    cout << "1. 커널 크기 자동 증가 (3~25)\n";
    cout << "2. 직접 커널 크기 입력해서 적용\n";
    cout << "선택 >> ";
    cin >> mode;

    // 원본 영상 디스플레이
    imshow("Original Image", src);
    moveWindow("Original Image", 100, 100);

    // Mode 1: 커널 크기를 자동으로 3부터 25까지 홀수로 증가시키며 필터 적용
    if (mode == 1) {
        for (int ksize = 3; ksize <= 25; ksize += 2) {
            medianBlur(src, dst, ksize);             // 미디언 필터 적용
            imshow("Median Filter Result", dst);     // 결과 영상 출력
            moveWindow("Median Filter Result", 750, 100); // 창 위치 설정
            waitKey(50); // 빠르게 넘어가도록 waitTime 줄임 (0.05초)
        }
    }
    // Mode 2: 사용자가 원하는 커널 크기를 입력해서 필터 적용
    else if (mode == 2) {
        int ksize;
        cout << "적용할 커널 크기(홀수)를 입력하세요: ";
        cin >> ksize;

        // 홀수 & 3 이상인지 유효성 검사
        if (ksize % 2 == 0 || ksize < 3) {
            cout << "?? 커널 크기는 3 이상의 홀수여야 합니다.\n";
            return;
        }

        medianBlur(src, dst, ksize);                 // 필터 적용
        imshow("Median Filter Result", dst);         // 결과 출력
        moveWindow("Median Filter Result", 750, 100);
        waitKey(0); // 결과 확인할 때까지 대기
    }
    // 잘못된 선택 시 안내
    else {
        cout << "잘못된 선택입니다.\n";
    }

    // 메모리 해제
    src.release();
    dst.release();
}
