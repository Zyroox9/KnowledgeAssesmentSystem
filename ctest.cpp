#include "ctest.h"

CTest::CTest()
{
    id = testsCreated++;
}

CTest::~CTest()
{

}

void CTest::checkAns()
{
    deque<bool> pts;

    for (int i=0; i<int(questions.size()); i++)
    {
        if(questions[i]->correctAns == studentAns[i])
            points.push_back(1);
        else
            points.push_back(0);
    }

   return;
}

int CTest::getId() {
    return id;
}

deque<SQuestion*> CTest::getQuestions() {
    return questions;
}

void CTest::setOwner(CStudent* ownr) {
    owner = ownr;
    return;
}

CStudent* CTest::getOwner() {
    return owner;
}

deque<bool> CTest::getPoints() {
    return points;
}

void CTest::setStudentAns(deque<int> studAns) {
    studentAns = studAns;
}

void CTest::addQuestion(SQuestion* quest) {
    questions.push_back(quest);
}

