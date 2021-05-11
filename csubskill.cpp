#include "csubskill.h"

CSubSkill::CSubSkill(double identification, string name_of_skill)
    :CSkill(identification, name_of_skill)
{
    type = 1;
}

CSubSkill::~CSubSkill()
{

}

deque<int> CSubSkill::listIds()
{
    deque<int> list;
    list.push_back(id);

    return list;
};
