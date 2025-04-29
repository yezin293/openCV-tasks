#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

// 적응적 이진화를 통해 rice 및 book2 이미지에서 객체(쌀, 글자)를 분리하는 함수
void runAdaptiveSegmentationDemo() {
    // 처리할 이미지 파일 리스트
    vector<string> imageFiles = { "rice.bmp", "book2.png" };

    // 각 이미지에 대해 반복 수행
    for (const string& filename : imageFiles) {
        // 이미지를 그레이스케일로 불러옴
        Mat src = imread(filename, IMREAD_GRAYSCALE);
        if (src.empty()) {
            cout << filename << " 불러오기 실패!" << endl;
            continue;
        }

        Mat blurred, preprocessed;
        // median blur를 통해 노이즈 제거 (특히 salt-and-pepper noise에 효과적)
        medianBlur(src, blurred, 5);

        // 히스토그램 평활화를 통해 명암 대비를 높임 (더 뚜렷한 이진화를 위해)
        equalizeHist(blurred, preprocessed);

        Mat meanResult, gaussianResult;
        int blockSize = 25;  // 블록 크기 (25x25 주변 이웃 영역을 기준으로 임계값 계산)
        int C = 5;           // 평균 또는 가중평균에서 빼주는 상수

        // 평균 기반 적응형 임계화
        adaptiveThreshold(preprocessed, meanResult, 255,
            ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSize, C);

        // 가우시안 기반 적응형 임계화
        adaptiveThreshold(preprocessed, gaussianResult, 255,
            ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blockSize, C);

        // 원본 및 결과 영상 출력
        imshow("Original - " + filename, src);
        imshow("Adaptive Mean - " + filename, meanResult);
        imshow("Adaptive Gaussian - " + filename, gaussianResult);
    }

    // 모든 창을 유지하다가 키 입력 시 종료
    waitKey(0);
    destroyAllWindows();
}
