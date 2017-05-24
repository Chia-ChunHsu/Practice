#include "pcaaxis.h"

PCAAxis::PCAAxis()
{

}

PCAAxis::PCAAxis(int number, cv::Point cnt, cv::Point p1, cv::Point p2)
{
    _number = number;
    _cnt = cnt;
    _p1 = p1;
    _p2 = p2;
    _length = calLength();
    _pc1 = cv::Point(p1.x-cnt.x,p1.y-cnt.y);
    _pc2 = cv::Point(p2.x-cnt.x,p2.y-cnt.y);

}

bool PCAAxis::compareLength(PCAAxis temp)
{
    if(this->_length>temp._length)
        return true;
    else
        return false;
}

int PCAAxis::getID()
{
    return _number;
}

int PCAAxis::getLength()
{
    return _length;
}

cv::Point PCAAxis::getPC1()
{
    return _pc1;
}

cv::Point PCAAxis::getPC2()
{
    return _pc2;
}

cv::Point PCAAxis::getCntP()
{
    return _cnt;
}

double PCAAxis::getPCL1()
{
    return _pclength1;
}

double PCAAxis::getPCL2()
{
    return _pclength2;
}

double PCAAxis::calLength()
{
    double length1 = pow(_cnt.x-_p1.x,2)+pow(_cnt.y-_p1.y,2);
    _pclength1 = sqrt(length1);
    double length2 = pow(_cnt.x-_p2.x,2)+pow(_cnt.y-_p2.y,2);
    _pclength2 = sqrt(length2);
    return sqrt(length1+length2);
}
