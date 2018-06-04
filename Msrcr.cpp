//
// Created by hyw on 18-6-1.
//
#include "Msrcr.h"

void Msrcr::Retinex(Mat src, Mat &dst, double sigma, int gain, int offset) {
    int ttype=CV_32FC1+(src.channels()-1)*8;
    Mat fA=Mat(src.rows,src.cols,ttype);
    Mat fB=Mat(src.rows,src.cols,ttype);
    Mat fC=Mat(src.rows,src.cols,ttype);
    src.convertTo(fA,ttype);
    fB=logMat(fA);
    GaussianBlur(src,src,Size(0,0),sigma);
    src.convertTo(fA,ttype);
    fC=logMat(fA);
    dst=fB-fC;
    dst.convertTo(dst,src.type(),gain,offset);
}
void Msrcr::MultiScaleRetinex(Mat src, Mat &dst, vector<double> weight, vector<double> sigmas, int gain, int offset) {

    Mat dst0=src.clone();
    for (int i=0;i<weight.size();i++)
    {
        Retinex(src,dst0,sigmas[i],gain,offset);
        dst+=dst0*weight[i];
    }
}


Mat Msrcr::logMat(Mat mat) {
    Mat dst = Mat(mat.rows, mat.cols, mat.type());
    for (int x = 0; x < mat.rows; x++) {
        for (int y = 0; y < mat.cols; y++) {
            if(mat.channels()==1) {
                dst.at<float>(x, y) = log(mat.at<float>(x, y));
            }
            else{
                dst.at<Vec3f>(x,y)[0]=log(mat.at<Vec3f>(x,y)[0]);
                dst.at<Vec3f>(x,y)[1]=log(mat.at<Vec3f>(x,y)[1]);
                dst.at<Vec3f>(x,y)[2]=log(mat.at<Vec3f>(x,y)[2]);
            }
        }
    }
    return dst;
}
