#ifndef CMAINSKILL_H
#define CMAINSKILL_H

#include "cskill.h"


class CMainSkill :public CSkill
{
public:
    virtual deque<int> listIds();
    void calculate();

    CMainSkill(double identification, string name_of_skill);
    ~CMainSkill();
};

#endif // CMAINSKILL_H
