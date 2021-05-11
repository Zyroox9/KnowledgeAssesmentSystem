#include "creport.h"

CReport::CReport()
{
    id = reportsCreated++;
}

void CReport::appendToOwner()
{
    owner->reports.push_back(id);
}

void CReport::updateOwnerKnowledge()
{
    for(int i=0; i<int(questions.size()); i++)
    {
        for(int j=0; j<int(questions[i]->testingSkillsOfID.size()); j++)
        {
            int skillId = questions[i]->testingSkillsOfID[j];
            CSkill* updatedSkill = owner->knowledge->search(skillId);
            double b = updatedSkill->confidenceBound;
            double x = updatedSkill->level;

            if(isCorrect[i])
                updatedSkill->level = - (pow(b,2) / 4 - 3*b /2 + 2) / (x + 1 - b/2) - b/2 + 2;
            else
                updatedSkill->level = - (pow(b,2) / 4 - 3*b /2 + 2) / (x + b/2 - 2) + b/2 - 1;

            updatedSkill->confidenceBound *=0.8;
        }
    }

    return;
}
