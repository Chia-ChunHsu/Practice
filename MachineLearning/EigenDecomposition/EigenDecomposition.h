#ifndef EIGENDECOMPOSITION_H
#define EIGENDECOMPOSITION_H

///
/// Author: Astrid Hsu
/// Brief: Eigendecomposition
/// Date: 2017-06-05
///
#include <algorithm>
#include <QDebug>

#define DECOMPOSITION_ARRAY 0

#ifdef HAVE_OPENCV
#include <opencv.hpp>
#define DECOMPOSITION_CVMAT 1
#endif

class EigenDecomposition
{
public:
    EigenDecomposition();
    EigenDecomposition(double **matrix, int matrixCol, int matrixRow);
#ifdef HAVE_OPENCV
    EigenDecomposition(cv::Mat matrix);
#endif
    // set the Matrix we want to decomposition, Matrix shoule be a square
//    void SetDecompositionMatrix();
//#ifdef HAVE_OPENCV
//    void SetDecompositionMatrix(cv::Mat matrix);
//#endif

    // Return the singular value
    void GetSingularValue(double *singularVal, int &size);
private:
    double **_matrix;
#if HAVE_OPENCV
    cv::Mat _matrixMat;
#endif
    int _col;
    int _row;
    void decomposition(int type);
    double *_singualarVal;
    int _size;
};

#endif // EIGENDECOMPOSITION_H
