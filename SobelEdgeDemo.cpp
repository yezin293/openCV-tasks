#include <opencv2/opencv.hpp>   // OpenCV 영상 처리 기본 헤더
#include <iostream>             // 표준 입출력 사용
#include "SobelEdgeDemo.h"      // 함수 선언 헤더 포함

using namespace cv;             // OpenCV 네임스페이스 사용
using namespace std;            // 표준 네임스페이스 사용

// Sobel 필터를 이용한 에지 검출 함수 정의
void runSobelEdgeDemo() {
    // 그레이스케일 이미지 로드 (lenna.jpg)
    Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);

    // 이미지 로드 실패 시 오류 메시지 출력 후 함수 종료
    if (src.empty()) {
        cout << "이미지를 불러올 수 없습니다!" << endl;
        return;
    }

    // 에지 결과를 저장할 변수 선언
    Mat sobel16, sobel8;

    // Sobel 연산 (1차 미분, X+Y 방향), 결과를 16비트 signed 타입에 저장
    Sobel(src, sobel16, CV_16S, 1, 1);

    // 결과를 시각화 가능한 8비트로 변환
    // scale = 1, offset = 0
    convertScaleAbs(sobel16, sobel8, 1, 0);

    // 원본 이미지 출력
    imshow("Original Image", src);
    moveWindow("Original Image", 100, 100); // 창 위치 조정

    // 에지 검출 결과 출력
    imshow("Sobel Edge Image", sobel8);
    moveWindow("Sobel Edge Image", 750, 100); // 창 위치 조정

    // 키 입력 대기 (사용자가 창 닫기 전까지)
    waitKey(0);

    // 메모리 해제
    src.release();
    sobel16.release();
    sobel8.release();
}
