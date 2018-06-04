#include "Msrcr.h"
using namespace std;
using namespace cv;

int main() {
    Mat src=imread("../3.png");
    Mat dst;
    Msrcr msrcr;
    msrcr.Retinex(src,dst,30,128,128);
    imshow("src",src);
    imshow("dst",dst);
    waitKey(0);
;
    return 0;
}
