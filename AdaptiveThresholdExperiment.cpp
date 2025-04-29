#include <opencv2/opencv.hpp>
#include <iostream>
#include "AdaptiveThresholdExperiment.h"

using namespace cv;
using namespace std;

// 적응형 이진화의 blockSize와 방법(Mean, Gaussian)에 따른 결과 비교 실험 함수
void runAdaptiveThresholdExperiment() {
    // 입력 이미지(book1.jpg)를 그레이스케일로 불러오기
    Mat src = imread("book1.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "book1.jpg 이미지를 불러올 수 없습니다!" << endl;
        return;
    }

    Mat img;
    // median blur를 적용하여 노이즈 제거
    medianBlur(src, img, 5);

    // 실험에 사용할 다양한 blockSize 값들 (홀수여야 함)
    vector<int> blockSizes = { 31, 45, 61 };
    int C = 2;  // 임계값 계산 후 빼주는 상수값
    int xOffset = 100, yOffset = 100; // 창 배치 기준 좌표
    int colGap = 350, rowGap = 300;   // 창 간격 조정

    // 각 blockSize에 대해 adaptiveThreshold 수행
    for (int i = 0; i < blockSizes.size(); i++) {
        int blockSize = blockSizes[i];

        Mat meanResult, gaussianResult;

        // 평균 기반 이진화
        adaptiveThreshold(img, meanResult, 255,
            ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSize, C);

        // 가우시안 기반 이진화
        adaptiveThreshold(img, gaussianResult, 255,
            ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blockSize, C);

        // 결과 이미지의 제목 설정
        string meanTitle = "Mean - blockSize " + to_string(blockSize);
        string gaussTitle = "Gaussian - blockSize " + to_string(blockSize);

        // 결과 영상 출력
        imshow(meanTitle, meanResult);
        imshow(gaussTitle, gaussianResult);

        // 창을 화면상에 정렬하여 비교가 용이하도록 배치
        int row = i / 2;
        int col = i % 2;
        moveWindow(meanTitle, xOffset + col * colGap, yOffset + row * rowGap);
        moveWindow(gaussTitle, xOffset + col * colGap + 150, yOffset + row * rowGap); // 조금 오른쪽으로 띄움
    }

    // 원본 영상(노이즈 제거된 영상) 출력
    imshow("Original (Median Blurred)", img);
    moveWindow("Original (Median Blurred)", xOffset + 2 * colGap, yOffset + rowGap);

    // 키 입력 시까지 대기 후 모든 창 닫기
    waitKey(0);
    destroyAllWindows();
}
