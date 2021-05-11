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
