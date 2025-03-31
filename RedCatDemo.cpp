#include <opencv2/opencv.hpp>   // OpenCV 헤더
#include <iostream>             // 표준 입출력
#include "RedCatDemo.h"         // 함수 선언 헤더

using namespace cv;             // OpenCV 네임스페이스
using namespace std;            // 표준 네임스페이스

// 빨간 필터를 적용한 영상 저장 함수
void runRedCatVideoDemo() {
    // Cat.mp4 동영상 열기
    VideoCapture cap("Cat.mp4");

    // 영상 열기에 실패했을 경우 메시지 출력 후 종료
    if (!cap.isOpened()) {
        cout << "Cat.mp4 영상을 열 수 없습니다!" << endl;
        return;
    }

    // 영상 정보 가져오기
    int width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));   // 가로 해상도
    int height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT)); // 세로 해상도
    int fps = static_cast<int>(cap.get(CAP_PROP_FPS));             // 프레임 속도

    // VideoWriter 객체 생성 (RedCat.avi로 저장)
    VideoWriter writer("RedCat.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'),
        fps, Size(width, height));

    // 저장 파일 열기 실패 시 메시지 출력 후 종료
    if (!writer.isOpened()) {
        cout << "출력 파일을 생성할 수 없습니다!" << endl;
        return;
    }

    Mat frame, modified; // 원본 프레임과 수정된 프레임

    // 프레임 단위로 반복 처리
    while (true) {
        cap >> frame;              // 다음 프레임 읽기
        if (frame.empty()) break;  // 영상 끝이면 종료

        modified = frame.clone();  // 원본 복사 → 편집용

        // 모든 픽셀에 대해 빨간색 채널(R)만 50 증가
        for (int y = 0; y < modified.rows; y++) {
            for (int x = 0; x < modified.cols; x++) {
                Vec3b& pixel = modified.at<Vec3b>(y, x); // 픽셀 접근 (BGR)
                pixel[2] = min(255, pixel[2] + 50);      // R 채널만 증가 (최대 255)
            }
        }

        imshow("RedCat Video", modified); // 화면에 출력
        writer.write(modified);           // 저장

        if (waitKey(30) == 27) break; // ESC 키 누르면 루프 종료
    }

    // 자원 정리
    cap.release();
    writer.release();
    destroyAllWindows();
}
