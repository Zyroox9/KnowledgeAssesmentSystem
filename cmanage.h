#ifndef CMANAGE_H
#define CMANAGE_H

#include <sstream>

#include "ctester.h"
#include "cdatabase.h"


class CManage
{
private:
    CDataBase* dataBase;
    CTester* tester;

    void testTheStudent();
    void createQuestion();
    void createStudent();
    void initiateTest();
    void testAndCheck();
    void checkKnowledge();

public:
    void play();

    CManage();
};

#endif // CMANAGE_H
