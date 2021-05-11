#include "cdatabase.h"

CDataBase::CDataBase()
{
    skillTreeSample = new CSkillTree;
}

CTest* CDataBase::getTestById(int id)
{
    return testBase[id];
}

CStudent* CDataBase::getStudentById(int id)
{
    return studentBase[id];
}

CReport* CDataBase::getReportById(int id)
{
    return reportBase[id];
}

SQuestion* CDataBase::getQuestionById(int id)
{
    return questionBase[id];
}

void CDataBase::addQuestion(SQuestion* newQuestion)
{
    char decision;

    cout<<endl<<"Zaakceptowac pytanie? (t/n)"<<endl;
    cin>>decision;

    if(decision == 't'){
        newQuestion->id = newQuestion->questionsCreated++;
        questionBase.push_back(newQuestion);
        cout<<endl<<"Pytanie zapisane."<<endl;
    } else if(decision == 'n')
        cout<<"Pytanie odrzucone."<<endl;
          else {
             cout<<"Podano niepoprawna litere"<<endl;
             addQuestion(newQuestion);
                }
    cout<<endl;
}

void CDataBase::addStudent(CStudent *newStudent)
{

    char decision;

    cout<<endl<<"Dodac ucznia? (t/n)"<<endl;
    cin>>decision;

    if(decision == 't'){
        studentBase.push_back(newStudent);
        cout<<endl<<"Uczen dodany.";
    } else if(decision == 'n')
        cout<<"Uczen nie dodany.";
          else {
             cout<<"Podano niepoprawna litere";
             addStudent(newStudent);
                }
    cout<<endl;
}

void CDataBase::addTest(CTest* newTest)
{
    testBase.push_back(newTest);
}

void CDataBase::addReport(CReport *newReport)
{
    reportBase.push_back(newReport);
}

void CDataBase::updateTest(CTest* newTest)
{
    int testId = newTest->id;
    testBase[testId] = newTest;
}
