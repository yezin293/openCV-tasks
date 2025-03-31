#include <opencv2/opencv.hpp>  // OpenCV 기본 라이브러리
#include <iostream>            // 콘솔 입출력용
#include <string>              // 문자열 처리
#include <iomanip>             // 숫자 포맷 조정용
#include <sstream>             // 문자열 스트림 처리용
#include "LaneDemo.h"          // 함수 선언 포함한 헤더파일

using namespace cv;            // OpenCV 네임스페이스 사용
using namespace std;           // 표준 네임스페이스 사용

// 차선 검출 함수
void runLaneDemo() {
    string folder = "./Lane1/"; // 차선 이미지가 저장된 폴더 경로

    for (int i = 1; i <= 12; i++) { // 1번 ~ 12번 이미지 순회
        stringstream ss;
        ss << folder << setfill('0') << setw(5) << i << ".jpg"; // 파일명 포맷팅: 00001.jpg
        string filename = ss.str();

        Mat src = imread(filename, IMREAD_GRAYSCALE); // 그레이스케일로 이미지 읽기
        if (src.empty()) {
            cout << "이미지를 불러올 수 없습니다: " << filename << endl;
            continue;
        }

        // Sobel 연산을 위한 변수 선언
        Mat gradX, gradY, magnitude, angle, mask;

        // X, Y 방향 Sobel 필터 적용 → 에지 방향과 강도 추출
        Sobel(src, gradX, CV_32F, 1, 0); // x축 미분
        Sobel(src, gradY, CV_32F, 0, 1); // y축 미분

        // magnitude: 에지 강도, angle: 방향 (도 단위)
        cartToPolar(gradX, gradY, magnitude, angle, true); // true → 도 단위 반환

        mask = Mat::zeros(src.size(), CV_8UC1); // 검출 결과를 저장할 마스크 (0으로 초기화)
        int imgCenter = src.cols / 2;           // 이미지 중심 x좌표
        int horizon = src.rows / 2;             // 화면 중간 y좌표 (상단 무시)

        // 이미지 전체 픽셀 반복
        for (int y = 0; y < src.rows; y++) {
            for (int x = 0; x < src.cols; x++) {
                float ang = angle.at<float>(y, x);     // 해당 픽셀의 방향
                float mag = magnitude.at<float>(y, x); // 해당 픽셀의 에지 강도

                if (y < horizon) continue; // 상단 영역 무시 (차선은 하단에만 존재)

                // 왼쪽 차선 조건: 중심 왼쪽, 에지 강도 충분, 방향 범위
                if (x < imgCenter && mag > 60 && ang >= 30 && ang <= 50)
                    mask.at<uchar>(y, x) = 255; // 흰색 표시 (차선으로 인식)

                // 오른쪽 차선 조건: 중심 오른쪽, 대칭적으로 방향 범위 확장
                if (x >= imgCenter && mag > 60 && ang >= 118 && ang <= 155)
                    mask.at<uchar>(y, x) = 255;
            }
        }

        // ROI 마스크 설정: 하단의 ∧ 모양만 남김 (불필요한 영역 제거)
        Mat roiMask = Mat::zeros(src.size(), CV_8UC1); // ROI 초기화
        int w = src.cols, h = src.rows;

        // ROI 영역 꼭짓점 정의 (넓은 V자 형태)
        Point roiPts[1][4] = {
            { Point(w * 0.02, h), Point(w * 0.35, h * 0.52),
              Point(w * 0.65, h * 0.52), Point(w * 0.98, h) }
        };

        const Point* ppt[1] = { roiPts[0] }; // 꼭짓점 포인터 배열
        int npt[] = { 4 };                  // 꼭짓점 개수

        // ROI 채우기
        fillPoly(roiMask, ppt, npt, 1, Scalar(255)); // ROI 영역을 흰색으로 채움

        // ROI 범위 안의 검출 결과만 남기기
        bitwise_and(mask, roiMask, mask);

        // 결과 출력
        imshow("Original Frame", src);       // 원본 영상 출력
        imshow("Detected Lane Pixels", mask); // 차선 검출 결과 출력
        waitKey(200); // 다음 이미지로 넘어가기 전 0.2초 대기
    }

    destroyAllWindows(); // 모든 창 닫기
}
