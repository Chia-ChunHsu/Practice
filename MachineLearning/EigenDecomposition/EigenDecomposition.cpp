#include "EigenDecomposition.h"

EigenDecomposition::EigenDecomposition()
{

}

EigenDecomposition::EigenDecomposition(double **matrix,int matrixCol,int matrixRow)
{
    // Avoid User input non-square matrix
    assert(matrixCol!=matrixRow);
    _matrix = matrix;
    _col = matrixCol;
    _row = matrixRow;
    decomposition(DECOMPOSITION_ARRAY);
}

EigenDecomposition::EigenDecomposition(cv::Mat matrix)
{
    // Avoid User input an error cv::Mat Type
    assert(matrix.type()!=CV_64FC1);
    // Avoid User input non-square matrix
    assert(matrix.rows!=matrix.cols);
    _matrixMat = matrix.clone();
    _col = matrix.cols;
    _row = matrix.rows;
}

//void EigenDecomposition::SetDecompositionMatrix()
//{

//}

void EigenDecomposition::GetSingularValue(double *singularVal,int &size)
{
    singularVal = _singualarVal;
    size = _size;
}

void EigenDecomposition::decomposition(int type)
{
    switch (type) {
    case DECOMPOSITION_ARRAY:
    {
        for(int i=0;i<_row;i++)
        {
            for(int j=0;j<_col;j++)
                qDebug()<<_matrix[i][j];
        }
        //Determinant Function, Call Determinant Class
        break;
    }
    case DECOMPOSITION_CVMAT:

        break;
    }
}
