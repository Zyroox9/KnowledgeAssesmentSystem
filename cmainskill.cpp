#include "cmainskill.h"


CMainSkill::CMainSkill(double identification, string name_of_skill)
    :CSkill(identification, name_of_skill)
{
    type = 0;
}

CMainSkill::~CMainSkill()
{

}


deque<int> CMainSkill::listIds()
{
    deque<int> list;

    search(list);

    return list;
};

void CMainSkill::calculate()
{
    deque <int> list;
    double levelSum = 0;
    double confidenceSum = 0;

    sumChildren(list, confidenceSum, levelSum);

    level = levelSum / int(list.size());
    setConfidenceBoud(confidenceSum / list.size());

    return;
}

