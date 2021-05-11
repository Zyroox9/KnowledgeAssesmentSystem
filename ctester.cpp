#include "ctester.h"

CTester::CTester(CDataBase* db)
{
    dataBase = db;
}

CTester::~CTester()
{

}

void CTester::randomTest(int numberOfQ)
{
    srand(time(NULL));
    int qId;
    CTest* newTest = new CTest;
    CDataBase *tempDB = new CDataBase;
    tempDB->questionBase = dataBase->questionBase;


    for(int i = 0; i < numberOfQ; i++)
    {
        qId = rand() % int(tempDB->questionBase.size());
        newTest->addQuestion(tempDB->questionBase[qId]);
        tempDB->questionBase.erase(tempDB->questionBase.begin() + qId);
    }

    dataBase->addTest(newTest);
    test = newTest;
}


void CTester::testASkill(int skillId, int numberOfQ)
{
    srand(time(NULL));
    int qId;
    CTest* newTest = new CTest;
    deque<SQuestion*> temporary;
    deque<int> skillIdList;

    CSkill* wantedSkill = dataBase->skillTreeSample->search(skillId);
    skillIdList = wantedSkill->listIds();

    //Tworzenie deque ze wszystkimi pytaniami testującymi dany skill
    for(int i = 0; i < int(dataBase->questionBase.size()); i++)
    {
        for(int j = 0; j < int(dataBase->questionBase[i]->testingSkillsOfID.size()); j++)
        {
            for(int k = 0; k < int(skillIdList.size()); k++)
            {
                if(dataBase->questionBase[i]->testingSkillsOfID[j] == skillIdList[k])
                    temporary.push_back(dataBase->questionBase[i]);
            }
        }
    }

    //Losowanie spośród wyselekcjonowanych pytań
    for(int i = 0; i < numberOfQ; i++)
    {
        qId = rand() % int(temporary.size());
        newTest->addQuestion(temporary[qId]);
        temporary.erase(temporary.begin() + qId);
    }

    dataBase->addTest(newTest);
    test = newTest;
}


void CTester::getAnswers()
{
    int ans;
    deque<int> totalAns;

    cout<<endl<<"----------------------- TEST ------------------------------";
    for(int i = 0; i < int(test->getQuestions().size()); i++)
    {
        cout<<endl<<"Zadanie "<<i + 1;
        cout<<endl<<test->getQuestions()[i]->text<<endl<<endl;

        for (int j = 0; j < int(test->getQuestions()[i]->answers.size()); j++)
            cout<<j+1<<" "<<test->getQuestions()[i]->answers[j]<<endl;
        cout<<endl;
        cin>>ans;
        totalAns.push_back(ans - 1);
        cout<<endl<<endl<<"Twoja odpowiedz: "<<test->getQuestions()[i]->answers[ans-1]<<endl<<endl;

    }

    test->setStudentAns(totalAns);
    cout<<endl<<"----------------- Odpowiedzi zapisane -------------------"<<endl;

    dataBase->updateTest(test);

    return;
}

void CTester::generateReport()
{
    CReport* newReport = new CReport;

    test->checkAns();

    newReport->owner = test->getOwner();
    newReport->isCorrect = test->getPoints();


    newReport->questions = test->getQuestions();

    dataBase->addReport(newReport);
    newReport->appendToOwner();
    newReport->updateOwnerKnowledge();
}

