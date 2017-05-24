#ifndef SIMILARPCA_H
#define SIMILARPCA_H
///
/// Author: Astrid Hsu
/// Brief: A method to compare the difference between the two PCs.
///        I tried to compare them by using the dot product(PC1 only).
/// Date: 20170524
///

#ifdef HAVE_OPENCV
#include <opencv.hpp>
#endif

#include <mypca.h>
#include <pcaaxis.h>

//#include <QDebug>

class SimilarPCA: public myPCA
{
public:
    SimilarPCA();
    SimilarPCA(cv::Mat srcMat);
    void getInterestPoint(std::vector<cv::Point> &interestP);
private:
    void Initial();
    void DeleteOutLier();
//    void CombinationNearby();
//    void findGroupP();
    double calDotProduct(PCAAxis ax1,PCAAxis ax2);
    std::vector<cv::Point> CntP;
    std::vector<cv::Point> P1;
    std::vector<cv::Point> P2;
    std::vector<cv::Point> _interestP;
    std::vector<PCAAxis> axis;
    cv::Mat _srcMat;
};

#endif // SIMILARPCA_H
