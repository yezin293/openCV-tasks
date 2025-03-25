#include <opencv2/opencv.hpp> // OpenCV 라이브러리 포함
#include <iostream> // 표준 입출력 라이브러리 포함

using namespace cv;  // OpenCV 네임스페이스 사용
using namespace std; // 표준 네임스페이스 사용

// 과제 2번 부분 영상을 독립적으로 추출하고 반전 처리 후 별도의 창에 디스플레이하는 함수
void runExtractRegion() {
    // 원본 이미지 로드
    Mat src = imread("Lenna.jpg");

    // 이미지가 정상적으로 로드되지 않았을 경우 오류 메시지 출력 후 종료
    if (src.empty()) {
        cout << "이미지를 로드할 수 없습니다!" << endl;
        return;
    }

    // 관심 영역(ROI) 설정 (시작 좌표: (200,200), 크기: 100x100)
    Rect roi(200, 200, 100, 100);

    // 독립적인 부분 영상 생성 (clone()을 사용해 원본과 별개로 저장)
    Mat region = src(roi).clone();

    // 부분 영상 반전 처리
    bitwise_not(region, region);

    // 원본 영상 출력
    imshow("Original Image", src);

    // 반전된 부분 영상 출력 (별도의 창으로 표시)
    imshow("Inverted Region", region);

    // 사용자가 키 입력할 때까지 대기 (창이 닫히지 않도록)
    waitKey(0);
}
