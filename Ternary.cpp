#include <opencv2/opencv.hpp> // OpenCV 라이브러리 포함
#include <iostream> // 표준 입출력 라이브러리 포함

using namespace cv;  // OpenCV 네임스페이스 사용
using namespace std; // 표준 네임스페이스 사용

// 삼진화(Ternary Threshold) 처리 함수 (원본 영상도 함께 출력)
void runTernaryThreshold() {
    // "Lenna.jpg" 이미지를 불러오는데, IMREAD_GRAYSCALE 옵션을 사용하여 그레이스케일로 로드
    Mat src = imread("Lenna.jpg", IMREAD_GRAYSCALE);

    // 이미지가 정상적으로 로드되지 않았을 경우 오류 메시지 출력 후 종료
    if (src.empty()) {
        cout << "이미지를 로드할 수 없습니다!" << endl;
        return;
    }

    // 원본 이미지를 복사하여 삼진화 결과를 저장할 Mat 객체 생성
    Mat ternary = src.clone();

    // 모든 픽셀을 순회하면서 삼진화 적용
    for (int y = 0; y < src.rows; y++) {  // 행(세로 방향) 순회
        for (int x = 0; x < src.cols; x++) {  // 열(가로 방향) 순회
            uchar pixel = src.at<uchar>(y, x); // 현재 픽셀 밝기 값 가져오기

            // 삼진화 적용
            if (pixel < 85)
                ternary.at<uchar>(y, x) = 0;      // 어두운 영역(0~84)은 검은색(0)
            else if (pixel < 170)
                ternary.at<uchar>(y, x) = 128;    // 중간 밝기 영역(85~169)은 회색(128)
            else
                ternary.at<uchar>(y, x) = 255;    // 밝은 영역(170~255)은 흰색(255)
        }
    }

    // 원본 영상 출력
    imshow("Original Image", src);

    // 삼진화된 영상 출력
    imshow("Ternary Image", ternary);

    //창 위치 조정 (원본 영상 왼쪽, 삼진화된 영상 오른쪽 배치)
    moveWindow("Original Image", 100, 100);   // 원본 영상 창을 (100,100)에 배치
    moveWindow("Ternary Image", 750, 100);   // 삼진화된 영상을 오른쪽(750,100)에 배치

    // 사용자가 키 입력할 때까지 대기 (창이 바로 닫히지 않도록)
    waitKey(0);

    // 동적으로 할당된 메모리 해제 (OpenCV에서는 필요 없지만 추가)
    src.release();
    ternary.release();
}
