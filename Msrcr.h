//
// Created by hyw on 18-6-1.
//

#ifndef TEST1_MSRCR_H
#define TEST1_MSRCR_H

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Msrcr
{
public:
    void Retinex(Mat src,Mat &dst,double sigma, int gain=128,int offset=128);
    void MultiScaleRetinex(Mat src,Mat &dst,vector<double> weight, vector<double> sigmas, int gain = 128, int offset = 128);

    Mat logMat(Mat mat);
};

#endif //TEST1_MSRCR_H
