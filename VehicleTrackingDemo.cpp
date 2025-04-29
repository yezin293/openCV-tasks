#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "VehicleTrackingDemo.h"

using namespace std;
using namespace cv;

// 100번째 프레임에서 추출한 차량 템플릿을 이용하여, 이후 프레임에서 차량을 추적하는 함수
void runVehicleTrackingDemo() {
    // 프레임 이미지와 템플릿 이미지가 저장된 폴더 경로
    string folder = "./carTracing/";
    string templatePath = folder + "Template_Car_100.bmp";

    // 최초 템플릿 이미지 로딩 (100번째 프레임에서 잘라낸 차량 영역)
    Mat templ = imread(templatePath, IMREAD_COLOR);
    if (templ.empty()) {
        cout << "템플릿 로딩 실패: " << templatePath << endl;
        return;
    }

    // 템플릿 크기 저장
    int templWidth = templ.cols;
    int templHeight = templ.rows;

    // 이전 프레임에서의 매칭 위치 저장 변수
    Point prevMatchLoc(-1, -1);

    // 101번 프레임부터 260번 프레임까지 반복
    for (int i = 101; i <= 260; ++i) {
        // 프레임 파일 경로 생성
        stringstream ss;
        ss << folder << setfill('0') << setw(5) << i << ".jpg";
        string imagePath = ss.str();

        // 현재 프레임 이미지 로딩
        Mat frame = imread(imagePath, IMREAD_COLOR);
        if (frame.empty()) {
            cout << "프레임 로딩 실패: " << imagePath << endl;
            continue;
        }

        // 템플릿 매칭 결과 저장용 이미지 생성
        Mat result;
        int result_cols = frame.cols - templ.cols + 1;
        int result_rows = frame.rows - templ.rows + 1;
        result.create(result_rows, result_cols, CV_32FC1);

        // TM_SQDIFF 방식으로 매칭 수행 (작을수록 유사도가 높음)
        double minVal, maxVal;
        Point minLoc, maxLoc;
        matchTemplate(frame, templ, result, TM_SQDIFF);
        minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

        // 매칭된 위치
        Point matchLoc = minLoc;

        // 추적된 차량 영역 표시 (빨간 사각형)
        rectangle(frame, matchLoc,
            Point(matchLoc.x + templWidth, matchLoc.y + templHeight),
            Scalar(0, 0, 255), 2);

        // 매칭 신뢰도 판단 (minVal이 작을수록 신뢰도 높음)
        bool trustScore = (minVal < 1e7);

        // 위치 안정성 판단 (이전 위치와 너무 멀면 불안정)
        bool positionStable = true;
        double dx = 0, dy = 0;

        if (prevMatchLoc.x >= 0) {
            dx = abs(matchLoc.x - prevMatchLoc.x);
            dy = abs(matchLoc.y - prevMatchLoc.y);
            if (dx > 100 || dy > 100) {
                positionStable = false;
            }
        }

        // 신뢰도가 충분하거나 위치가 안정적인 경우에만 템플릿을 갱신
        if (trustScore || positionStable) {
            // 템플릿이 영상 범위를 넘지 않는 경우에만 갱신
            if (matchLoc.x + templWidth <= frame.cols &&
                matchLoc.y + templHeight <= frame.rows) {
                // 현재 매칭 영역을 템플릿으로 갱신
                templ = frame(Rect(matchLoc.x, matchLoc.y, templWidth, templHeight)).clone();
                prevMatchLoc = matchLoc;
                cout << "프레임 " << i << ": 템플릿 갱신 (minVal = " << minVal << ")" << endl;
            }
            else {
                cout << "프레임 " << i << ": 갱신 실패 (템플릿 범위 초과)" << endl;
            }
        }
        else {
            // 매칭 품질 및 위치 안정성이 부족하여 갱신 보류
            cout << "프레임 " << i << ": 갱신 보류 - 신뢰도 낮고 위치도 불안정 (minVal = "
                << minVal << ", dx = " << dx << ", dy = " << dy << ")" << endl;
        }

        // 결과 시각화
        imshow("Vehicle Tracking", frame);
        waitKey(30);  // 프레임 간 간격 조절 (약 30ms 대기)
    }

   
}
