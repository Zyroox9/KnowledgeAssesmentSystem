#include "cskill.h"

using namespace std;

CSkill::CSkill(double identification, string name_of_skill)
{
    id = identification;
    name = name_of_skill;
}

CSkill::~CSkill()
{

}

void CSkill::add_child(CSkill *child)
{
    this->children.push_back(child);
    child->parents.push_back(this);
}


deque<int> CSkill::listIds()
{
    //funkcja wirtualna
}

void CSkill::search(deque<int> &list)
{

    for(int i=0; i<int(children.size());i++)
    {
        if(children[i]->type == 1)
        {
            bool is = true;

            for(int j=0; j<int(list.size());j++)
                if(list[j] == children[i]->id)
                    is = false;

            if(is == true)
                list.push_back(children[i]->id);

            children[i]->search(list);
        }

    }
    return;
}
