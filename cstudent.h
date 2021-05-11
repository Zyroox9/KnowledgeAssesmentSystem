#ifndef CSTUDENT_H
#define CSTUDENT_H

#include "cskilltree.h"

class CStudent
{
public:
    static int studentsCreated;
    int id;
    string firstname;
    string surname;
    deque<int> reports;
    CSkillTree* knowledge;

    CStudent(string firstname, string surname);

};

#endif // CSTUDENT_H
