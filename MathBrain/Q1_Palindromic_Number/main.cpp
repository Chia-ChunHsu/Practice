// Author:
// Problem:
#include <QCoreApplication>
#include <iostream>
bool isPalindromic10(int testNum)
{
    std::string array = std::to_string(testNum);
    int i;
    for(i = 0;i<(array.length())/2+1;i++)
    {
        if(array.at(i) != array.at(array.length()-i-1))
        {
            break;
        }
    }
    if(i-1==(array.length())/2)
    {
        return true;
    }
    return false;
}

bool isPalindromic2(int testNum)
{
    std::string array="";
    std::vector<int> storageTemp;

    int dividend = testNum;
    int divisor = 2;
    while(dividend >= divisor)
    {
        storageTemp.push_back(dividend%divisor);
        dividend = dividend/divisor;
    }
    storageTemp.push_back(dividend%divisor);

    for(int i=storageTemp.size()-1;i>=0;i--)
    {
        array+=std::to_string(storageTemp[i]);
    }
    int i;
    for(i = 0;i<(array.length())/2+1;i++)
    {
        if(array.at(i) != array.at(array.length()-i-1))
        {
            break;
        }
    }

    if(i-1==(array.length())/2)
    {
        return true;
    }
    return false;
}

bool isPalindromic8(int testNum)
{
    std::string array="";
    std::vector<int> storageTemp;

    int dividend = testNum;
    int divisor = 8;
    while(dividend >= divisor)
    {
        storageTemp.push_back(dividend%divisor);
        dividend = dividend/divisor;
    }
    storageTemp.push_back(dividend%divisor);

    for(int i=storageTemp.size()-1;i>=0;i--)
    {
        array+=std::to_string(storageTemp[i]);
    }
    int i;
    for(i = 0;i<(array.length())/2+1;i++)
    {
        if(array.at(i) != array.at(array.length()-i-1))
        {
            break;
        }
    }

    if(i-1==(array.length())/2)
    {
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //需要找到十進位+二進位+八進位都是回文數且大於10的值

    int result = 0;
    int testNum = 10;
    while(result == 0)
    {
        testNum ++;

        if(isPalindromic10(testNum)&& isPalindromic2(testNum)&&isPalindromic8(testNum))
        {
            result = 1;
            break;
        }

    }
    std::cout<<"Result "<<testNum<<std::endl;

    return a.exec();
}
