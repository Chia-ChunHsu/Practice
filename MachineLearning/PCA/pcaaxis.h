#ifndef PCAAXIS_H
#define PCAAXIS_H
///
/// Author: Astrid Hsu
/// Brief: Container to storge the PCA vector, PC1 and  PC2.
///        Also conclude some compare function, such as vector length and dot product.
/// Date: 20170524
///
#ifdef HAVE_OPENCV
#include <opencv.hpp>
#endif

class PCAAxis
{
public:
    PCAAxis();
    PCAAxis(int number,cv::Point cnt,cv::Point p1,cv::Point p2);
    bool compareDot(PCAAxis temp);
    bool compareLength(PCAAxis temp);
    int getID();
    int getLength();
    cv::Point getPC1();
    cv::Point getPC2();
    cv::Point getCntP();
    double getPCL1();
    double getPCL2();
private:
    double calLength();
    int _number;
    cv::Point _cnt;
    cv::Point _p1;
    cv::Point _p2;
    double _length;
    cv::Point _pc1;
    cv::Point _pc2;
    double _pclength1;
    double _pclength2;
};

#endif // PCAAXIS_H
