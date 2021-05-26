#ifndef CDATABASE_H
#define CDATABASE_H

#include <QSqlDatabase>

#include "ctest.h"


class CDataBase
{
    deque<CStudent*> studentBase;
    deque<CTest*> testBase;
    deque<CReport*> reportBase;
    deque<SQuestion*> questionBase;
    CSkillTree *skillTreeSample;


    CTest* getTestById(int id);
    CStudent* getStudentById(int id);
    CReport* getReportById(int id);
    SQuestion* getQuestionById(int id);

    void addQuestion(SQuestion* newQuestion);
    void addStudent(CStudent* newStudent);
    void addTest(CTest* newTest);
    void addReport(CReport* newReport);

    void updateTest(CTest* newTest);

    CDataBase();

    friend class CTester;
    friend class CManage;
};

#endif // CDATABASE_H
