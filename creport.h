#ifndef CREPORT_H
#define CREPORT_H

#include <cmath>

#include "cstudent.h"
#include "squestion.h"


using namespace std;

class CReport
{
public:
    static int reportsCreated;
    int id;
    CStudent* owner;
    deque<SQuestion*> questions;
    deque<bool> isCorrect;

    void appendToOwner();
    void updateOwnerKnowledge();

    CReport();
};

#endif // CREPORT_H
