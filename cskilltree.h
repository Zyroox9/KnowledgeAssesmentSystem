#ifndef CSKILLTREE_H
#define CSKILLTREE_H

#include "cskill.h"
#include "cmainskill.h"
#include "csubskill.h"
#include "cconskill.h"

class CSkillTree
{
public:
    vector<CSkill *> linear;

    CSkill* search (int id);

    CSkillTree();

    friend class CStudent;
};

#endif // CSKILLTREE_H
