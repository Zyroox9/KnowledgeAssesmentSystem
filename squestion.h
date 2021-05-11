#ifndef SQUESTION_H
#define SQUESTION_H

#include <string>
#include <vector>

using namespace std;

struct SQuestion
{
    static int questionsCreated;

    int id;
    vector<int> testingSkillsOfID;
    string text;
    int correctAns;
    vector<string> answers;
};

#endif // SQUESTION_H
