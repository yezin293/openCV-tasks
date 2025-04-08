#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

// 형태학적 그래디언트를 이용한 외곽선 추출 함수
void runMorphGradientDemo() {
    // 처리할 이미지 파일 리스트
    string files[] = { "lena.bmp", "letterj.png" };

    for (int i = 0; i < 2; ++i) {
        Mat src = imread(files[i], IMREAD_GRAYSCALE);
        if (src.empty()) {
            cout << files[i] << " 이미지를 불러올 수 없습니다!" << endl;
            continue;
        }

        // 5x5 사각형 구조 요소 생성
        Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));

        // 형태학적 그래디언트 수행
        Mat gradient;
        morphologyEx(src, gradient, MORPH_GRADIENT, element);

        // 출력
        string winOriginal = "Original - " + files[i];
        string winResult = "Morph Gradient - " + files[i];

        imshow(winOriginal, src);
        moveWindow(winOriginal, 100 + 600 * i, 100);

        imshow(winResult, gradient);
        moveWindow(winResult, 100 + 600 * i, 400);
    }

    waitKey(0);
    destroyAllWindows();
}
