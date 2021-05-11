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

    CSkill::search(list);

    return list;
};


