#include "similarpca.h"

SimilarPCA::SimilarPCA()
{

}

SimilarPCA::SimilarPCA(cv::Mat srcMat)
{
    _srcMat = srcMat.clone();
    setSrcMat(srcMat);
    FindPC(srcMat);
    getCntPoints(CntP);
    getPoint1(P1);
    getPoint2(P2);
    Initial();
}

void SimilarPCA::getInterestPoint(std::vector<cv::Point> &interestP)
{
    interestP.assign(_interestP.begin(),_interestP.end());
}

void SimilarPCA::Initial()
{
    axis.clear();
    for(int i=0;i<CntP.size();i++)
    {
        axis.push_back(PCAAxis(i,CntP[i],P1[i],P2[i]));
    }
    DeleteOutLier();
}

void SimilarPCA::DeleteOutLier()
{
    cv::Mat SimiliarMat = cv::Mat::zeros(axis.size(),axis.size(),CV_64FC1);
    for(int i=0;i<axis.size();i++)
    {
        for(int j=0;j<axis.size();j++)
        {
            double value = calDotProduct(axis[i], axis[j]);
            SimiliarMat.at<double>(i,j) = value;
        }
    }
    std::vector<int> selectIndex;
    for(int i =0;i<SimiliarMat.rows;i++)
    {
        //double multi =1.0;
        int cal =0;
        for(int j=0;j<SimiliarMat.cols;j++)
        {
            if(SimiliarMat.at<double>(i,j)<0.3)
                cal++;
        }
        if(cal<SimiliarMat.cols/2)
        {
            selectIndex.push_back(i);
        }
    }
    cv::Mat result = _srcMat.clone();
    _interestP.clear();
    for(int i=0;i<selectIndex.size();i++)
    {
        //cv::circle(result,axis[selectIndex[i]].getCntP(),3,cv::Scalar(0,0,255),-1,8,0);
        _interestP.push_back(axis[selectIndex[i]].getCntP());
    }
    //cv::imshow("result_based_On_PC1",result);
}

double SimilarPCA::calDotProduct(PCAAxis ax1, PCAAxis ax2)
{
    return (ax1.getPC1().x*ax2.getPC1().x+ax1.getPC1().y*ax2.getPC1().y)/ax1.getPCL1()/ax2.getPCL1();
}
