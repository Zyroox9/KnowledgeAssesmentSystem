#ifndef CTEST_H
#define CTEST_H

#include "creport.h"

class CTest
{
    int id;
    static int testsCreated;

    deque<SQuestion*> questions;
    deque<int> studentAns;
    CStudent* owner;
    deque<bool> points;
    CReport* result;   

public:
    int getId();
    deque<SQuestion*> getQuestions();
    void setOwner(CStudent* ownr);
    CStudent* getOwner();
    deque<bool> getPoints();
    void setStudentAns(deque<int> studAns);
    void addQuestion(SQuestion* quest);

    void checkAns();


    CTest();
    ~CTest();


};

#endif // CTEST_H
