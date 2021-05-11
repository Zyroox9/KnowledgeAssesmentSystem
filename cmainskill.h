#ifndef CMAINSKILL_H
#define CMAINSKILL_H

#include "cskill.h"


class CMainSkill :public CSkill
{
    virtual deque<int> listIds();

    CMainSkill(double identification, string name_of_skill);
    ~CMainSkill();

public:
    void calculate();

    friend class CSkillTree;
};

#endif // CMAINSKILL_H
