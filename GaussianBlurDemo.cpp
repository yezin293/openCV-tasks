#include <opencv2/opencv.hpp>   // OpenCV 기본 헤더 (영상 처리용)
#include <iostream>             // 표준 입출력 라이브러리
#include "GaussianBlurDemo.h"  // 헤더파일 포함 (함수 선언)

using namespace cv;             // OpenCV 네임스페이스 사용
using namespace std;           // std 네임스페이스 사용

// 가우시안 필터 데모 함수 정의
void runGaussianBlurDemo() {
    // 컬러 이미지 불러오기 (lenna.jpg 사용)
    Mat src = imread("lenna.jpg", IMREAD_COLOR);

    // 이미지 로드 실패 시 오류 메시지 출력 후 종료
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다!" << endl;
        return;
    }

    Mat dst; // 결과 영상 저장용

    // 사용자에게 모드 선택 받기
    int mode;
    cout << "\n[GaussianBlur 데모 모드 선택]\n";
    cout << "1. 커널 크기 증가하며 적용 (sigma 자동)\n";
    cout << "2. sigmaX, sigmaY 직접 지정 (Size 자동)\n";
    cout << "선택 >> ";
    cin >> mode;

    // 원본 영상 디스플레이
    imshow("Original Image", src);
    moveWindow("Original Image", 100, 100);

    // Mode 1: 커널 크기를 점점 키우면서 GaussianBlur 적용
    if (mode == 1) {
        for (int i = 1; i < 61; i += 2) { // 커널 크기 1~59까지 홀수로 증가
            GaussianBlur(src, dst, Size(i, i), 0, 0); // sigma 자동 계산
            imshow("Gaussian Filter Result", dst);   // 결과 영상 출력
            moveWindow("Gaussian Filter Result", 750, 100); // 창 위치 조정
            waitKey(50); // 0.05초 대기 후 다음 커널로 진행 (디버깅 빠르게)
        }
    }

    // Mode 2: sigmaX, sigmaY 값을 직접 입력받아서 필터 적용
    else if (mode == 2) {
        double sigmaX, sigmaY;
        cout << "sigmaX 값을 입력하세요: ";
        cin >> sigmaX;
        cout << "sigmaY 값을 입력하세요: ";
        cin >> sigmaY;

        // 커널 크기 자동 결정 (Size = 0), 입력된 시그마값으로 적용
        GaussianBlur(src, dst, Size(0, 0), sigmaX, sigmaY);
        imshow("Gaussian Filter Result", dst);
        moveWindow("Gaussian Filter Result", 750, 100);
        waitKey(0); // 키 입력 기다림 (실험 끝날 때까지 대기)
    }

    // 잘못된 숫자 입력 시 처리
    else {
        cout << "잘못된 입력입니다.\n";
    }

    // 메모리 해제
    src.release();
    dst.release();
}
