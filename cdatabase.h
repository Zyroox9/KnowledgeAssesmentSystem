#ifndef CDATABASE_H
#define CDATABASE_H

#include "ctest.h"


class CDataBase
{
private:
    deque<CStudent*> studentBase;
    deque<CTest*> testBase;
    deque<CReport*> reportBase;
    deque<SQuestion*> questionBase;
    CSkillTree *skillTreeSample;

public:
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
};

#endif // CDATABASE_H
