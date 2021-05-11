#ifndef CSKILLTREE_H
#define CSKILLTREE_H

#include "cskill.h"
#include "cmainskill.h"
#include "csubskill.h"
#include "cconskill.h"

class CSkillTree
{
    vector<CSkill *> linear;

    public:
    CSkill* search (int id);
    vector<CSkill *> getLinear();

    CSkillTree();

   friend class CStudent;
};

#endif // CSKILLTREE_H
