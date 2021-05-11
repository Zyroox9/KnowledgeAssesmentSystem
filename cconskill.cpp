#include "cconskill.h"

CConSkill::CConSkill(double identification, string name_of_skill)
    :CSkill(identification, name_of_skill)
{
    type = 2;
}

CConSkill::~CConSkill()
{

}


deque<int> CConSkill::listIds()
{
    deque<int> list;

    if(children[0]->type == 1)
        search(list);
    else
        for(int i=0; i<int(children.size()); i++)
            children[i]->search(list);

    return list;
};

void CConSkill::calculate()
{
    double levelSum = 0;
    double confidenceSum = 0;

    for(int i=0; i<int(children.size()); i++)
    {
        levelSum += children[i]->getLevel();
        confidenceSum += children[i]->getConfidenceBound();
    }

    level = levelSum / children.size();
    setConfidenceBoud(confidenceSum / children.size());

    return;
}
