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
        if(interestPoint[i].y> average_y && interestPoint[i].y-average_y<sigma_y)
            interestPy.push_back(interestPoint[i]);
        else if(interestPoint[i].y < average_y && average_y - interestPoint[i].y<sigma_y)
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

    //LineScan
    cv::Mat lineMat = srcMat.clone();
    cv::line(lineMat,cv::Point(lineMat.cols,b*lineMat.cols+a),cv::Point(0,0*b+a),cv::Scalar(0,0,255),1,8,0);
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
    cv::Mat lineStorMat;// = srcMat.clone();
    cv::Mat rotateMat( 2, 3, CV_32FC1 );
    rotateMat = cv::getRotationMatrix2D(cv::Point(average_nx,average_ny),atan(b)/3.1415*180,1.0);
    cv::warpAffine(srcMat,lineStorMat,rotateMat,srcMat.size());
    cv::imshow("lineStorMat",lineStorMat);
    int x00 = sqrt(pow(Py[0].x-average_nx,2)+pow(Py[0].x*b+a-(average_ny-upper)-average_ny,2))*cos(atan(b));
    int y00 = sqrt(pow(Py[0].x-average_nx,2)+pow(Py[0].x*b+a-(average_ny-upper-average_ny),2))*sin(atan(b));
    int x01 = sqrt(pow(Py[Py.size()-1].x-average_nx,2)+pow(Py[Py.size()-1].x*b+a-(average_ny-upper)-average_ny,2))*cos(atan(b));
    int y01 = sqrt(pow(Py[Py.size()-1].x-average_nx,2)+pow(Py[Py.size()-1].x*b+a-(average_ny-upper)-average_ny,2))*sin(atan(b));
    int x10 = sqrt(pow(Py[0].x-average_nx,2)+pow(Py[0].x*b+a+(lower-average_ny)-average_ny,2))*cos(atan(b));
    int y10 = sqrt(pow(Py[0].x-average_nx,2)+pow(Py[0].x*b+a-(average_ny-upper-average_ny),2))*sin(atan(b));
    int x11 = sqrt(pow(Py[Py.size()-1].x-average_nx,2)+pow(Py[Py.size()-1].x*b+a-(average_ny-upper)-average_ny,2))*cos(atan(b));
    int y11 = sqrt(pow(Py[Py.size()-1].x-average_nx,2)+pow(Py[Py.size()-1].x*b+a-(average_ny-upper)-average_ny,2))*sin(atan(b));
    //qDebug()<<"("<<x00<<","<<y00<<")"<<" ("<<x01<<","<<y01<<")"<<" ("<<x10<<","<<y10<<") ("<<x11<<","<<y11<<")";
    //qDebug()<<"("<<0<<","<<lower<<")"<<" ("<<x01<<","<<y01<<")"<<" ("<<x10<<","<<y10<<") ("<<x11<<","<<y11<<")";
    cv::Rect ROI(0,upper*0.9,lineStorMat.cols,lower*1.1-upper*0.9);
    cv::Mat IMat = lineStorMat(ROI).clone();
    cv::imwrite("ROI.jpg",IMat);
    cv::line(lineStorMat,cv::Point(0,lower),cv::Point(lineStorMat.cols-1,lower),cv::Scalar(0,0,255),1,8,0);
    cv::line(lineStorMat,cv::Point(0,upper),cv::Point(lineStorMat.cols-1,upper),cv::Scalar(0,0,255),1,8,0);
    cv::imshow("lineStorMat2",lineStorMat);
    //cv::line(lineStorMat,cv::Point(Py[0].x,Py[0].x*b+a+(lower-average_ny)),cv::Point(Py[Py.size()-1].x,Py[Py.size()-1].x*b+a+(lower-average_ny)),cv::Scalar(0,0,255),1,8,0);

    cv::line(lineStorMat,cv::Point(Py[0].x,Py[0].x*b+a-(average_ny-upper)),cv::Point(Py[Py.size()-1].x,Py[Py.size()-1].x*b+a-(average_ny-upper)),cv::Scalar(0,0,255),1,8,0);
    cv::line(lineStorMat,cv::Point(Py[0].x,Py[0].x*b+a+(lower-average_ny)),cv::Point(Py[Py.size()-1].x,Py[Py.size()-1].x*b+a+(lower-average_ny)),cv::Scalar(0,0,255),1,8,0);


    //    cv::line(lineMat,cv::Point(Py[0].x,upper),cv::Point(Py[Py.size()-1].x,upper),cv::Scalar(0,0,255),1,8,0);
//    cv::line(lineMat,cv::Point(Py[0].x,lower),cv::Point(Py[Py.size()-1].x,lower),cv::Scalar(0,0,255),1,8,0);
    cv::line(lineMat,cv::Point(Py[0].x,Py[0].x*b+a-(average_ny-upper)),cv::Point(Py[Py.size()-1].x,Py[Py.size()-1].x*b+a-(average_ny-upper)),cv::Scalar(0,0,255),1,8,0);
    cv::line(lineMat,cv::Point(Py[0].x,Py[0].x*b+a+(lower-average_ny)),cv::Point(Py[Py.size()-1].x,Py[Py.size()-1].x*b+a+(lower-average_ny)),cv::Scalar(0,0,255),1,8,0);

    cv::imshow("upperLowerLineMat",lineMat);
}

int LimitPoint::changeValue(cv::Mat src, double a, double b, int initialX, int endX,int offset)
{
    int Val = 0;
    cv::Mat grayMat;
    cv::cvtColor(src,grayMat,CV_BGR2GRAY);
    cv::threshold(grayMat,grayMat,100,255,CV_THRESH_BINARY);
    for(int i=initialX;i<endX-1;i++)
    {
        if(i*b+a+offset < src.rows)
            if(abs(grayMat.at<uchar>(int(i*b+a+offset),i)-grayMat.at<uchar>(int((i+1)*b+a+offset),(i+1)))>100)
                Val++;
    }
    return Val;
}

