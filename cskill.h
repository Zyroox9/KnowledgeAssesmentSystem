#ifndef CSKILL_H
#define CSKILL_H

#include <vector>
#include <string>
#include <deque>
#include <iostream>


using namespace std;

class CSkill
{

    string name;
    double confidenceBound = 1;

    void add_child(CSkill *child);


protected:
    vector<CSkill *> parents;
    vector<CSkill *> children;
    int id;
    double level = 0.5;

    CSkill(double identification, string name_of_skill);
    virtual ~CSkill();

public:
    int type;

    void search(deque<int> &list);
    void sumChildren(deque<int> &list, double &confSum, double &lvlSum);
    virtual deque<int> listIds();
    double getLevel();
    void setLevel(double newLvl);
    double getConfidenceBound();
    void updateConfidenceBound();
    void setConfidenceBoud(double confBound);
    int getId();

    friend class CSkillTree;
};

#endif // CSKILL_H
