#include <opencv2/opencv.hpp>
#include <iostream>
#include "TemplateMatchingDemo.h"

using namespace std;
using namespace cv;

// 다양한 템플릿 매칭 기준을 적용하여 유사 영역을 탐색하고 비교하는 함수
void runTemplateMatchingDemo() {
    // ---------------- Lena 매칭 ----------------

    // Lena 이미지 불러오기 (그레이스케일 및 컬러)
    Mat lena_gray = imread("lena.bmp", IMREAD_GRAYSCALE);
    Mat lena_color = imread("lena.bmp", IMREAD_COLOR);
    // Lena의 참조 템플릿 이미지 불러오기
    Mat lena_ref = imread("lena_ref.bmp", IMREAD_GRAYSCALE);
    if (lena_gray.empty() || lena_ref.empty() || lena_color.empty()) {
        cout << "lena 이미지 로딩 실패!" << endl;
        return;
    }

    // TM_SQDIFF 방식: 차이값의 제곱합을 기준으로 최소값 위치 탐색
    Mat res1;
    matchTemplate(lena_gray, lena_ref, res1, TM_SQDIFF);
    Point minLoc1;
    minMaxLoc(res1, nullptr, nullptr, &minLoc1, nullptr);
    // 매칭 결과 표시 (빨간 사각형)
    Mat lena1 = lena_color.clone();
    rectangle(lena1, minLoc1,
        Point(minLoc1.x + lena_ref.cols, minLoc1.y + lena_ref.rows),
        Scalar(0, 0, 255), 2);
    imshow("Lena - TM_SQDIFF", lena1);
    imshow("Template - Lena", lena_ref);

    // TM_CCOEFF 방식: 상관 계수를 기준으로 최대값 위치 탐색
    Mat res2;
    matchTemplate(lena_gray, lena_ref, res2, TM_CCOEFF);
    Point maxLoc2;
    minMaxLoc(res2, nullptr, nullptr, nullptr, &maxLoc2);
    // 매칭 결과 표시 (파란 사각형)
    Mat lena2 = lena_color.clone();
    rectangle(lena2, maxLoc2,
        Point(maxLoc2.x + lena_ref.cols, maxLoc2.y + lena_ref.rows),
        Scalar(255, 0, 0), 2);
    imshow("Lena - TM_CCOEFF", lena2);

    // ---------------- Test1 매칭 ----------------

    // Test1 이미지 및 참조 템플릿 불러오기
    Mat test1 = imread("test1.bmp", IMREAD_COLOR);
    Mat temp1 = imread("test1_ref.bmp", IMREAD_GRAYSCALE);
    Mat test1_gray;
    cvtColor(test1, test1_gray, COLOR_BGR2GRAY);
    if (test1.empty() || temp1.empty()) {
        cout << "test1 이미지 로딩 실패!" << endl;
        return;
    }

    // TM_SQDIFF 방식으로 매칭 수행
    Mat res3;
    matchTemplate(test1_gray, temp1, res3, TM_SQDIFF);
    Point minLoc3;
    minMaxLoc(res3, nullptr, nullptr, &minLoc3, nullptr);
    Mat test1_draw = test1.clone();
    rectangle(test1_draw, minLoc3,
        Point(minLoc3.x + temp1.cols, minLoc3.y + temp1.rows),
        Scalar(0, 0, 255), 2);
    imshow("Test1 - TM_SQDIFF", test1_draw);
    imshow("Template - Test1", temp1);

    // ---------------- Test2 매칭 ----------------

    // Test2 이미지 및 템플릿 불러오기
    Mat test2 = imread("test2.bmp", IMREAD_COLOR);
    Mat temp2 = imread("test2_ref.bmp", IMREAD_GRAYSCALE);
    Mat test2_gray;
    cvtColor(test2, test2_gray, COLOR_BGR2GRAY);
    if (test2.empty() || temp2.empty()) {
        cout << "test2 이미지 로딩 실패!" << endl;
        return;
    }

    // TM_SQDIFF 방식으로 매칭 수행
    Mat res4;
    matchTemplate(test2_gray, temp2, res4, TM_SQDIFF);
    Point minLoc4;
    minMaxLoc(res4, nullptr, nullptr, &minLoc4, nullptr);
    Mat test2_draw = test2.clone();
    rectangle(test2_draw, minLoc4,
        Point(minLoc4.x + temp2.cols, minLoc4.y + temp2.rows),
        Scalar(0, 0, 255), 2);
    imshow("Test2 - TM_SQDIFF", test2_draw);
    imshow("Template - Test2", temp2);

    // 키 입력 대기 후 종료
    waitKey(0);
    destroyAllWindows();
}
