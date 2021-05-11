#include "cstudent.h"

CStudent::CStudent(string first, string sur)
{
    id = studentsCreated++;
    firstname = first;
    surname = sur;

    knowledge = new CSkillTree;
}

void CStudent::addReport(int repId)
{
    reports.push_back(repId);
    return;
}

CSkillTree* CStudent::getKnowledge()
{
    return knowledge;
}
