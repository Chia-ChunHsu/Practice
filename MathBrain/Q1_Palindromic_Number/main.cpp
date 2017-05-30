// Author:
// Problem:
#include <QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //需要找到十進位+二進位+八進位都是回文數且大於10的值


    //10 進位

    int result = 0;
    int testNum = 10;
    while(result == 0)
    {
        testNum ++;

        std::string array = std::to_string(testNum);
        int i;
        for(i = 0;i<(array.length())/2+1;i++)
        {
            if(array.at(i) != array.at(array.length()-i-1))
            {
                std::cout<<array.at(i)<<" != "<<array.at(array.length()-i-1)<<std::endl;
                break;
            }
        }
        std::cout<<i<<"  "<<array.length()<<std::endl;
        if(i-1==(array.length())/2)
        {
            std::cout<<i<<"  "<<(array.length())/2<<std::endl;
            result = testNum;

        }

    }
    std::cout<<"Result "<<testNum<<std::endl;

    return a.exec();
}
