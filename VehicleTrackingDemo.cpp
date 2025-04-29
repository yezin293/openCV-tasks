#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "VehicleTrackingDemo.h"

using namespace std;
using namespace cv;

// 100��° �����ӿ��� ������ ���� ���ø��� �̿��Ͽ�, ���� �����ӿ��� ������ �����ϴ� �Լ�
void runVehicleTrackingDemo() {
    // ������ �̹����� ���ø� �̹����� ����� ���� ���
    string folder = "./carTracing/";
    string templatePath = folder + "Template_Car_100.bmp";

    // ���� ���ø� �̹��� �ε� (100��° �����ӿ��� �߶� ���� ����)
    Mat templ = imread(templatePath, IMREAD_COLOR);
    if (templ.empty()) {
        cout << "���ø� �ε� ����: " << templatePath << endl;
        return;
    }

    // ���ø� ũ�� ����
    int templWidth = templ.cols;
    int templHeight = templ.rows;

    // ���� �����ӿ����� ��Ī ��ġ ���� ����
    Point prevMatchLoc(-1, -1);

    // 101�� �����Ӻ��� 260�� �����ӱ��� �ݺ�
    for (int i = 101; i <= 260; ++i) {
        // ������ ���� ��� ����
        stringstream ss;
        ss << folder << setfill('0') << setw(5) << i << ".jpg";
        string imagePath = ss.str();

        // ���� ������ �̹��� �ε�
        Mat frame = imread(imagePath, IMREAD_COLOR);
        if (frame.empty()) {
            cout << "������ �ε� ����: " << imagePath << endl;
            continue;
        }

        // ���ø� ��Ī ��� ����� �̹��� ����
        Mat result;
        int result_cols = frame.cols - templ.cols + 1;
        int result_rows = frame.rows - templ.rows + 1;
        result.create(result_rows, result_cols, CV_32FC1);

        // TM_SQDIFF ������� ��Ī ���� (�������� ���絵�� ����)
        double minVal, maxVal;
        Point minLoc, maxLoc;
        matchTemplate(frame, templ, result, TM_SQDIFF);
        minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

        // ��Ī�� ��ġ
        Point matchLoc = minLoc;

        // ������ ���� ���� ǥ�� (���� �簢��)
        rectangle(frame, matchLoc,
            Point(matchLoc.x + templWidth, matchLoc.y + templHeight),
            Scalar(0, 0, 255), 2);

        // ��Ī �ŷڵ� �Ǵ� (minVal�� �������� �ŷڵ� ����)
        bool trustScore = (minVal < 1e7);

        // ��ġ ������ �Ǵ� (���� ��ġ�� �ʹ� �ָ� �Ҿ���)
        bool positionStable = true;
        double dx = 0, dy = 0;

        if (prevMatchLoc.x >= 0) {
            dx = abs(matchLoc.x - prevMatchLoc.x);
            dy = abs(matchLoc.y - prevMatchLoc.y);
            if (dx > 100 || dy > 100) {
                positionStable = false;
            }
        }

        // �ŷڵ��� ����ϰų� ��ġ�� �������� ��쿡�� ���ø��� ����
        if (trustScore || positionStable) {
            // ���ø��� ���� ������ ���� �ʴ� ��쿡�� ����
            if (matchLoc.x + templWidth <= frame.cols &&
                matchLoc.y + templHeight <= frame.rows) {
                // ���� ��Ī ������ ���ø����� ����
                templ = frame(Rect(matchLoc.x, matchLoc.y, templWidth, templHeight)).clone();
                prevMatchLoc = matchLoc;
                cout << "������ " << i << ": ���ø� ���� (minVal = " << minVal << ")" << endl;
            }
            else {
                cout << "������ " << i << ": ���� ���� (���ø� ���� �ʰ�)" << endl;
            }
        }
        else {
            // ��Ī ǰ�� �� ��ġ �������� �����Ͽ� ���� ����
            cout << "������ " << i << ": ���� ���� - �ŷڵ� ���� ��ġ�� �Ҿ��� (minVal = "
                << minVal << ", dx = " << dx << ", dy = " << dy << ")" << endl;
        }

        // ��� �ð�ȭ
        imshow("Vehicle Tracking", frame);
        waitKey(30);  // ������ �� ���� ���� (�� 30ms ���)
    }

   
}
