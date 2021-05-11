#include "cmanage.h"


CManage::CManage()
{
    dataBase = new CDataBase;
    tester = new CTester(dataBase);
}

void CManage::testTheStudent()
{
    int studentId;
    int testId;

    cout<<endl<<"Studenta o jakim ID testujemy?"<<endl;
    cin>>studentId;

    CStudent* student = dataBase->getStudentById(studentId);

    cout<<endl<<"Jaki test wyswietlamy? (Podaj ID):"<<endl;
    cin>>testId;

    CTest* newTest = new CTest;
    newTest->getQuestions() = dataBase->getTestById(testId)->getQuestions();

    newTest->setOwner(student);
    tester->test = newTest;

    testAndCheck();

    return;
}

void CManage::createQuestion()
{
    string buffer;
    int correct;

    cin.sync();
    //Wczytywanie danych tworzących pytanie

    SQuestion* newQuestion = new SQuestion;
    cout<<"Podaj tresc nowego zadania:"<<endl;
    getline(cin, buffer);

    newQuestion->text = buffer;


    cout<<endl<<"Podaj id skilli, ktore sa testowane przez to zadanie, rozdzielone spacja lub przecinkiem:"<<endl;
    getline(cin, buffer);

    stringstream ss(buffer);

        for (int i; ss >> i;) {
            newQuestion->testingSkillsOfID.push_back(i);
            if (ss.peek() == ',' || ss.peek() == ' ')
                ss.ignore();
        }


     cout<<endl<<"Podaj mozliwe odpowiedzi na to pytanie, rozdzielone znakiem ;:"<<endl;
     getline(cin, buffer);

     stringstream ss1(buffer);

     while(ss1.good())
     {
         string substr;
         getline(ss1, substr, ';');
         newQuestion->answers.push_back(substr);
     }


     cout<<endl<<"Ktora z podanych odpowiedzi jest poprawna? (pierwsza to 1, druga to 2, itp.):"<<endl;
     cin>>correct;
     newQuestion->correctAns = correct - 1;

     //Wyświetlanie tworzonego pytania
     cout<<endl<<"-----------------------------------------------------"<<endl<<"Tresc nowego pytania: "<<newQuestion->text<<endl<<endl;
     cout<<"ID testowanych skilli: "<<endl;
     for (size_t i = 0; i < newQuestion->testingSkillsOfID.size(); i++)
         cout << newQuestion->testingSkillsOfID[i] << endl;
     cout<<endl<<"Mozliwe odpowiedzi: "<<endl;
     for (size_t i = 0; i < newQuestion->answers.size(); i++)
         cout << newQuestion->answers[i] << endl;
     cout<<endl<<"Poprawna odpowiedz: "<<newQuestion->answers[newQuestion->correctAns]<<endl<<"-----------------------------------------------------";


     dataBase->addQuestion(newQuestion);

     return;
}

void CManage::createStudent()
{

    string name, surname;
    cout<<endl<<"Podaj imie nowego ucznia:"<<endl;
    cin>>name;
    cout<<endl<<"Podaj nazwisko nowego ucznia:"<<endl;
    cin>>surname;
    CStudent* newStudent = new CStudent(name, surname);
    dataBase->addStudent(newStudent);

    return;
}

void CManage::initiateTest()
{
    char choice;
    int numberOfQ;
    int studentId;

    cout<<endl<<"Studenta o jakim ID testujemy?"<<endl;
    cin>>studentId;

    CStudent* student = dataBase->getStudentById(studentId);

    cout<<endl<<"Chcesz wygenerowac test losowy, czy sprawdzajacy konkretny skill? (l-losowy/k-konkretny):"<<endl;
    cin>>choice;

    if(choice == 'l') {
        cout<<endl<<"Z ilu pytan ma sie skladac test?"<<endl;
        cin>>numberOfQ;
        tester->randomTest(numberOfQ);
    } else if(choice == 'k') {
        int skillId;

        cout<<endl<<"Z ilu pytan ma sie skladac test?"<<endl;
        cin>>numberOfQ;
        cout<<endl<<"Jaki skill chcesz sprawdzic? (podaj ID)"<<endl;
        cin>>skillId;
        tester->testASkill(skillId, numberOfQ);
    } else {
        cout<<endl<<"Inicjalizacja testu przerwana."<<endl;
        return;
    }

    tester->test->setOwner(student);

    testAndCheck();

    return;
}

void CManage::testAndCheck()
{
    tester->getAnswers();
    tester->generateReport();

    return;
}

void CManage::play()
{
    char option;

    while(true)
    {
        cout<<endl<<"-----------------------------------------------------------------";
        cout<<endl<<"Wybierz akcje:"<<endl<<endl<<"1 - dodaj ucznia"<<endl<<"2 - dodaj pytanie"<<endl;
        cout<<"3 - inicjuj test"<<endl<<"4 - testuj ucznia istniejacym testem"<<endl<<"5 - sprawdz stan wiedzy ucznia"<<endl<<endl;
        cin>>option;

        switch (option) {
            case '1':
                createStudent();
                break;

            case '2':
                createQuestion();
                break;

            case '3':
                initiateTest();
                break;

            case '4':
                testTheStudent();
                break;

            case '5':
                checkKnowledge();
                break;

        default:
            cout<<"Wybierz poprawna opcje."<<endl;
        }

    }
}

void CManage::checkKnowledge()
{
    int studentId;

    cout<<endl<<"Ucznia o jakim ID sprawdzamy?"<<endl;
    cin>>studentId;

    CStudent* student = dataBase->getStudentById(studentId);

    cout<<endl<<"Posiada "<<student->knowledge->getLinear()[0]->getLevel()<<"% "<<"wiedzy maturalnej."<<endl<<endl;
}
