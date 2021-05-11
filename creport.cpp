#include "creport.h"

CReport::CReport()
{
    id = reportsCreated++;
}

void CReport::appendToOwner()
{
    owner->addReport(id);
}

void CReport::updateOwnerKnowledge()
{
    //Uwzględniając każde pytanie, zmieniamy dany w danym SubSkillu level i confidenceBound
    for(int i=0; i<int(questions.size()); i++)
    {
        for(int j=0; j<int(questions[i]->testingSkillsOfID.size()); j++)
        {
            int skillId = questions[i]->testingSkillsOfID[j];
            CSkill* updatedSkill = owner->getKnowledge()->search(skillId);
            double b = updatedSkill->getConfidenceBound();
            double x = updatedSkill->getLevel();
            double newLevel;

            if(isCorrect[i])
                newLevel = - (pow(b,2) / 4 - 3*b /2 + 2) / (x + 1 - b/2) - b/2 + 2;
            else
                newLevel = - (pow(b,2) / 4 - 3*b /2 + 2) / (x + b/2 - 2) + b/2 - 1;

            updatedSkill->setLevel(newLevel);
            updatedSkill->updateConfidenceBound();
        }
    }

    //Update wszystkich MainSkilli
    vector<CSkill*> studentKnowledge = owner->getKnowledge()->getLinear();

    for(int i=0; i<int(studentKnowledge.size()); i++)
    {
        CMainSkill* mainSkill = dynamic_cast<CMainSkill*>(studentKnowledge[i]);
        CConSkill* conSkill = dynamic_cast<CConSkill*>(studentKnowledge[i]);

        if(mainSkill != NULL)
            mainSkill->calculate();
        if(conSkill != NULL)
            conSkill->calculate();
    }

    return;
}
