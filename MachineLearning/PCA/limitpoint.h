#ifndef LIMITPOINT_H
#define LIMITPOINT_H

#ifdef HAVE_OPENCV
#include <opencv.hpp>
#endif

#include <QDebug>

class LimitPoint
{
public:
    LimitPoint();
    LimitPoint(cv::Mat srcMat,std::vector<cv::Point> interestPoint);
private:
    int changeValue(cv::Mat src, double a, double b, int initialX, int endX, int offset);
};

#endif // LIMITPOINT_H
