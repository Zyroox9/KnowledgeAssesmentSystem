#ifndef CSKILL_H
#define CSKILL_H

#include <vector>
#include <string>
#include <deque>
#include <iostream>


using namespace std;

class CSkill
{
public:
    vector<CSkill *> parents;
    vector<CSkill *> children;
    string name;
    int id;
    int type;
    double level = 0.5;
    double confidenceBound = 1;

    void add_child(CSkill *child);
    virtual deque<int> listIds();
    void search(deque<int> &list);

    CSkill(double identification, string name_of_skill);
    virtual ~CSkill();

    friend class CSkillTree;
};

#endif // CSKILL_H
