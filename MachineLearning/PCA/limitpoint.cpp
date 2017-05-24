#include "limitpoint.h"

LimitPoint::LimitPoint()
{

}

LimitPoint::LimitPoint(cv::Mat srcMat, std::vector<cv::Point> interestPoint)
{
    //delete dy outlier
    double average_y = 0;
    double y_square = 0;
    for(int i=0;i<interestPoint.size();i++)
    {
        average_y += interestPoint[i].y;
        y_square += pow(interestPoint[i].y,2);
    }
    average_y = average_y/interestPoint.size();

    double sigma_y = sqrt(y_square/interestPoint.size()-pow(average_y,2));

    std::vector<cv::Point> interestPy;
    cv::Mat pointdy = srcMat.clone();
    for(int i=0;i<interestPoint.size();i++)
    {
        if(abs(interestPoint[i].y-average_y)<sigma_y*2)
            interestPy.push_back(interestPoint[i]);
    }
    for(int i=0;i<interestPy.size();i++)
        cv::circle(pointdy,interestPy[i],3,cv::Scalar(0,0,255),-1,8,0);

    cv::imshow("Interest Point dy",pointdy);

    //linear regression
    double average_nx = 0;
    double average_ny = 0;
    for(int i=0;i<interestPy.size();i++)
    {
        average_nx += interestPy[i].x;
        average_ny += interestPy[i].y;
    }
    average_nx = average_nx/interestPy.size();
    average_ny = average_ny/interestPy.size();
    //L: y = a + bx
    double b = 0;
    double b_deno = 0;
    for(int i=0;i<interestPy.size();i++)
    {
        b+=(interestPy[i].x-average_nx)*(interestPy[i].y-average_ny);
        b_deno += pow(interestPy[i].x-average_nx,2);
    }
    b = b/b_deno;
    double a = average_ny-b*average_nx;



    std::vector<cv::Point> Py;
    //Delete y
    for(int i=0;i<interestPy.size();i++)
    {
        int x = interestPy[i].x;
        int y = interestPy[i].y;
        if(abs(b*x+a-y) < 8 )
            Py.push_back(interestPy[i]);
    }
    for(int i=0;i<Py.size();i++)
    {
        for(int j=i;j<Py.size();j++)
        {
            if(Py[i].x>Py[j].x)
            {
                cv::Point temp = Py[i];
                Py[i] = Py[j];
                Py[j] = temp;
            }
        }
    }
//    cv::Mat OPMat = srcMat.clone();
//    for(int i=0;i<Py.size();i++)
//        cv::circle(OPMat,Py[i],3,cv::Scalar(0,0,255),-1,8,0);
//    cv::imshow("OPMat",OPMat);

    //LineScan
    cv::Mat lineMat = srcMat.clone();
    cv::line(lineMat,cv::Point(Py[0].x,b*Py[0].x+a),cv::Point(Py[Py.size()-1].x,Py[Py.size()-1].x*b+a),cv::Scalar(0,0,255),1,8,0);
    cv::imshow("lineMat",lineMat);

    int initialVal = changeValue(srcMat,a,b,Py[0].x,Py[Py.size()-1].x,0);
    qDebug()<<"initialVal = "<<initialVal;
    //find upper
    //qDebug()<<"006";
    int upper =0;
    for(int i= b*Py[0].x + a - 1;i>=0;i--)
    {
        int t = changeValue(srcMat,a,b,Py[0].x,Py[Py.size()-1].x,b*Py[0].x+a-i);
        if(abs( t - initialVal)> initialVal/2 )
        {
            qDebug()<<"upper T = "<<t;
            upper = i;
            i = -1;
            //break;
        }
    }
    //find lower
    //qDebug()<<"007";
    int lower =0;
    for(int i= b*Py[0].x + a + 1;i<srcMat.rows;i++)
    {
        int t = changeValue(srcMat,a,b,Py[0].x,Py[Py.size()-1].x,i-(b*Py[0].x+a));
        if(abs( t-initialVal)>initialVal/2)
        {
            qDebug()<<"Lower = "<<t;
            lower = i;
            i = srcMat.rows;
            //break;
        }
    }
    //qDebug()<<"008";
    cv::line(lineMat,cv::Point(Py[0].x,upper),cv::Point(Py[Py.size()-1].x,upper),cv::Scalar(0,0,255),1,8,0);
    cv::line(lineMat,cv::Point(Py[0].x,lower),cv::Point(Py[Py.size()-1].x,lower),cv::Scalar(0,0,255),1,8,0);
    cv::imshow("upperLowerLineMat",lineMat);
}

int LimitPoint::changeValue(cv::Mat src, double a, double b, int initialX, int endX,int offset)
{
    //qDebug()<<"005";
    int Val = 0;
    cv::Mat grayMat;
    //qDebug()<<"0051";
    cv::cvtColor(src,grayMat,CV_BGR2GRAY);
    cv::threshold(grayMat,grayMat,100,255,CV_THRESH_BINARY);
    //qDebug()<<"0052";
    for(int i=initialX;i<endX-1;i++)
    {
        if(i*b+a+offset < src.rows)
            if(abs(grayMat.at<uchar>(int(i*b+a+offset),i)-grayMat.at<uchar>(int((i+1)*b+a+offset),(i+1)))>100)
                Val++;
    }
    //qDebug()<<"006";
    return Val;
}

