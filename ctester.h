#ifndef CTESTER_H
#define CTESTER_H

#include <ctime>

#include "cdatabase.h"

class CTester
{
    CTest* test;
    CDataBase* dataBase;

    void randomTest(int numberOfQ);
    void testASkill(int skillId, int numberOfQ);
    void getAnswers();
    void generateReport();

    CTester(CDataBase* db);
    ~CTester();

    friend class CManage;
};

#endif // CTESTER_H
