#ifndef CTEST_H
#define CTEST_H

#include "creport.h"

class CTest
{
public:
    int id;
    static int testsCreated;

    deque<SQuestion*> questions;
    deque<int> studentAns;
    CStudent* owner;
    deque<bool> points;
    CReport* result;   

    void checkAns();


    CTest();
    ~CTest();
};

#endif // CTEST_H
