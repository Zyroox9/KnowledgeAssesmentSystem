#ifndef CSUBSKILL_H
#define CSUBSKILL_H

#include "cskill.h"

class CSubSkill :public CSkill
{
public:
    virtual deque<int> listIds();

    CSubSkill(double identification, string name_of_skill);
    ~CSubSkill();
};

#endif // CSUBSKILL_H
