#include <opencv2/opencv.hpp> // OpenCV 라이브러리 포함
#include <iostream> // 표준 입출력 라이브러리 포함

using namespace cv;  // OpenCV 네임스페이스 사용
using namespace std; // 표준 네임스페이스 사용

// Otsu 알고리즘을 이용한 자동 임계값 이진화 함수
void runOtsuThreshold() {
    // "Lenna.jpg" 이미지를 불러오는데, IMREAD_GRAYSCALE 옵션을 사용하여 그레이스케일로 로드
    Mat src = imread("Lenna.jpg", IMREAD_GRAYSCALE);

    // 이미지가 정상적으로 로드되지 않았을 경우 오류 메시지 출력 후 종료
    if (src.empty()) {
        cout << "이미지를 로드할 수 없습니다!" << endl;
        return;
    }

    // 이진화를 위한 결과 Mat 객체 선언
    Mat binary;

    // Otsu의 이진화 적용
    // threshold(입력 영상, 출력 영상, 임계값, 최대값, 임계값 적용 방법)
    // THRESH_OTSU 옵션을 사용하면 임계값을 자동으로 결정해 줌
    threshold(src, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // 원본 영상 출력
    imshow("Original Image", src);

    // Otsu 이진화된 영상 출력
    imshow("Otsu Binary Image", binary);

    //창 위치 조정 (원본 영상 왼쪽, Otsu 이진화 영상 오른쪽 배치)
    moveWindow("Original Image", 100, 100);   // 원본 영상 창을 (100,100)에 배치
    moveWindow("Otsu Binary Image", 750, 100); // 이진화된 영상을 오른쪽(750,100)에 배치

    // 사용자가 키 입력할 때까지 대기 (창이 바로 닫히지 않도록)
    waitKey(0);

    // 동적으로 할당된 메모리 해제 (OpenCV에서는 필요 없지만 추가)
    src.release();
    binary.release();
}
