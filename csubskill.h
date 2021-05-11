#ifndef CSUBSKILL_H
#define CSUBSKILL_H

#include "cskill.h"

class CSubSkill :public CSkill
{
    virtual deque<int> listIds();

    CSubSkill(double identification, string name_of_skill);
    ~CSubSkill();

    friend class CSkillTree;
};

#endif // CSUBSKILL_H
