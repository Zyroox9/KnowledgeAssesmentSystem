#include <QCoreApplication>
#include<iostream>


#include "cmanage.h"

using namespace std;

int CStudent::studentsCreated = 0;
int SQuestion::questionsCreated = 0;
int CTest::testsCreated = 0;
int CReport::reportsCreated = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    CManage system;
    system.play();




    return a.exec();
}
