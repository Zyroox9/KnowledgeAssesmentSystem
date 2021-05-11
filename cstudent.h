#ifndef CSTUDENT_H
#define CSTUDENT_H

#include "cskilltree.h"

class CStudent
{
    static int studentsCreated;
    int id;
    string firstname;
    string surname;
    deque<int> reports;
    CSkillTree* knowledge;

    CStudent(string firstname, string surname);

public:
    void addReport(int repId);
    CSkillTree* getKnowledge();

    friend class CManage;
};

#endif // CSTUDENT_H
