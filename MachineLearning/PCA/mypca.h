#ifndef MYPCA_H
#define MYPCA_H

///
/// Author: Astrid Hsu
/// Brief: Simple PCA which is revised from OPENCV Tutorial: http://docs.opencv.org/3.2.0/d1/dee/tutorial_introduction_to_pca.html
/// Date: 20170524
///

#ifdef HAVE_OPENCV
#include <opencv.hpp>
#endif

class myPCA
{
public:
    myPCA();
    myPCA(cv::Mat srcMat);
    cv::Mat getResult();
    void setSrcMat(cv::Mat srcMat);
    void FindPC(cv::Mat srcMat);
    void getCntPoints(std::vector<cv::Point> &cntP);
    void getPoint1(std::vector<cv::Point> &p1);
    void getPoint2(std::vector<cv::Point> &p2);

private:
    void drawAxis(cv::Mat& img, cv::Point p, cv::Point q, cv::Scalar colour, const float scale);
    double getOrientation(const std::vector<cv::Point> &pts, cv::Mat&img);
    cv::Mat _result;
    cv::Mat _srcMat;
    std::vector<cv::Point> cntPoints;
    std::vector<cv::Point> P1Points;
    std::vector<cv::Point> P2Points;

};

#endif // MYPCA_H
