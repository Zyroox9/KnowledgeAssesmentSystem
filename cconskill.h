#ifndef CCONSKILL_H
#define CCONSKILL_H

#include "cskill.h"

class CConSkill :public CSkill
{
public:
    virtual deque<int> listIds();

    CConSkill(double identification, string name_of_skill);
    ~CConSkill();
};

#endif // CCONSKILL_H
