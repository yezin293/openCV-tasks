#include <opencv2/opencv.hpp>  //OpenCV 라이브러리 포함
#include <iostream> // 표준 입출력 라이브러리 포함

using namespace cv; //OpenCV 네임 스페이스 사용 
using namespace std; // 표준 네임 스페이스 사용 

//과제 1번에 대한 함수 
void runBlueImage() {
    //640x480 크기의 3채널 컬러 영상 Mat객체 생성
    //Scalar(255,0,0) -> 파란색
    Mat blueImage(480, 640, CV_8UC3, Scalar(255, 0, 0));
    // 생성된 영상을 화면에 출력 
    imshow("Blue Image", blueImage);
    //사용자 입력 키 대기 
    waitKey(0);
}
