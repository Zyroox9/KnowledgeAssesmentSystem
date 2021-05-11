#ifndef CCONSKILL_H
#define CCONSKILL_H

#include "cskill.h"

class CConSkill :public CSkill
{
    virtual deque<int> listIds();

    CConSkill(double identification, string name_of_skill);
    ~CConSkill();

public:
    void calculate();

    friend class CSkillTree;
};

#endif // CCONSKILL_H
