#include "mypca.h"

myPCA::myPCA()
{
    _srcMat = cv::Mat();
}

myPCA::myPCA(cv::Mat srcMat)
{
    _srcMat = srcMat.clone();
    FindPC(_srcMat);
}

cv::Mat myPCA::getResult()
{
    return _result;
}

void myPCA::setSrcMat(cv::Mat srcMat)
{
    _srcMat = srcMat.clone();
}

void myPCA::FindPC(cv::Mat srcMat)
{

    cv::Mat gray;
    cv::cvtColor(srcMat, gray, cv::COLOR_BGR2GRAY);
//    // Convert image to binary
    cv::Mat bw;
    cv::threshold(gray, bw, 50, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    // Find all the contours in the thresholded image
    std::vector<cv::Vec4i> hierarchy;
    std::vector<std::vector<cv::Point> > contours;
    cv::findContours(bw, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    _result = srcMat.clone();
    cntPoints.clear();
    P1Points.clear();
    P2Points.clear();
    for (size_t i = 0; i < contours.size(); ++i)
    {
        // Calculate the area of each contour
        double area = cv::contourArea(contours[i]);
        // Ignore contours that are too small or too large
        if (area < 1e2 || 1e5 < area) continue;
        // Draw each contour only for visualisation purposes
        cv::drawContours(_result, contours, static_cast<int>(i), cv::Scalar(0, 0, 255), 2, 8, hierarchy, 0);
        // Find the orientation of each shape
        getOrientation(contours[i], _result);
    }
}

void myPCA::getCntPoints(std::vector<cv::Point> &cntP)
{
    cntP.assign(cntPoints.begin(),cntPoints.end());
}

void myPCA::getPoint1(std::vector<cv::Point> &p1)
{
    p1.assign(P1Points.begin(),P1Points.end());
}

void myPCA::getPoint2(std::vector<cv::Point> &p2)
{
    p2.assign(P2Points.begin(),P2Points.end());
}

void myPCA::drawAxis(cv::Mat &img, cv::Point p, cv::Point q, cv::Scalar colour, const float scale = 0.2)
{
    double angle;
    double hypotenuse;
    angle = atan2( (double) p.y - q.y, (double) p.x - q.x ); // angle in radians
    hypotenuse = sqrt( (double) (p.y - q.y) * (p.y - q.y) + (p.x - q.x) * (p.x - q.x));
//    double degrees = angle * 180 / CV_PI; // convert radians to degrees (0-180 range)
//    cout << "Degrees: " << abs(degrees - 180) << endl; // angle in 0-360 degrees range
    // Here we lengthen the arrow by a factor of scale
    q.x = (int) (p.x - scale * hypotenuse * cos(angle));
    q.y = (int) (p.y - scale * hypotenuse * sin(angle));
    cv::line(img, p, q, colour, 1, CV_AA);
    // create the arrow hooks
    p.x = (int) (q.x + 9 * cos(angle + CV_PI / 4));
    p.y = (int) (q.y + 9 * sin(angle + CV_PI / 4));
    cv::line(img, p, q, colour, 1, CV_AA);
    p.x = (int) (q.x + 9 * cos(angle - CV_PI / 4));
    p.y = (int) (q.y + 9 * sin(angle - CV_PI / 4));
    cv::line(img, p, q, colour, 1, CV_AA);
}

double myPCA::getOrientation(const std::vector<cv::Point> &pts, cv::Mat &img)
{
    //Construct a buffer used by the pca analysis
    int sz = static_cast<int>(pts.size());
    cv::Mat data_pts = cv::Mat(sz, 2, CV_64FC1);
    for (int i = 0; i < data_pts.rows; ++i)
    {
        data_pts.at<double>(i, 0) = pts[i].x;
        data_pts.at<double>(i, 1) = pts[i].y;
    }
    //Perform PCA analysis
    cv::PCA pca_analysis(data_pts, cv::Mat(), CV_PCA_DATA_AS_ROW);
    //Store the center of the object
    cv::Point cntr = cv::Point(static_cast<int>(pca_analysis.mean.at<double>(0, 0)),
                      static_cast<int>(pca_analysis.mean.at<double>(0, 1)));
    //Store the eigenvalues and eigenvectors
    std::vector<cv::Point2d> eigen_vecs(2);
    std::vector<double> eigen_val(2);
    //qDebug()<<"pca_analysis.eigenvectors "<<pca_analysis.eigenvectors.type()<<pca_analysis.eigenvectors.rows<<pca_analysis.eigenvectors.cols;
    //qDebug()<<"pca_analysis.eigenvalues "<<pca_analysis.eigenvalues.type()<<pca_analysis.eigenvalues.rows<<pca_analysis.eigenvalues.cols;
    for (int i = 0; i < 2; ++i)
    {
        eigen_vecs[i] = cv::Point2d(pca_analysis.eigenvectors.at<double>(i, 0),
                                pca_analysis.eigenvectors.at<double>(i, 1));
        eigen_val[i] = pca_analysis.eigenvalues.at<double>(i, 0);
    }
    // Draw the principal components
    cv::circle(img, cntr, 3, cv::Scalar(255, 0, 255), 2);
    cv::Point p1 = cntr + 0.02 * cv::Point(static_cast<int>(eigen_vecs[0].x * eigen_val[0]), static_cast<int>(eigen_vecs[0].y * eigen_val[0]));
    cv::Point p2 = cntr - 0.02 * cv::Point(static_cast<int>(eigen_vecs[1].x * eigen_val[1]), static_cast<int>(eigen_vecs[1].y * eigen_val[1]));
    drawAxis(img, cntr, p1, cv::Scalar(0, 255, 0), 1);
    drawAxis(img, cntr, p2, cv::Scalar(255, 255, 0), 5);

    cntPoints.push_back(cntr);
    P1Points.push_back(p1);
    P2Points.push_back(p2);
    double angle = atan2(eigen_vecs[0].y, eigen_vecs[0].x); // orientation in radians
    return angle;
}
