#include "cstudent.h"

CStudent::CStudent(string first, string sur)
{
    id = studentsCreated++;
    firstname = first;
    surname = sur;

    knowledge = new CSkillTree;
}
