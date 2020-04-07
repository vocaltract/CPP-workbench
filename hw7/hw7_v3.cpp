#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

enum {POLITICS,ENGLISH,SOFTWARE,ML};

class Student
{
public:
    Student(const string& name, double* scores);
    virtual void score(double *score_list);
    void display_name();
protected:
    string name;
    double politics;
    double english;
};

class ComputerStudent:public Student
{
public:
    ComputerStudent(const string& name, double *scores);
    void score(double *score_list);
protected:
    double software;
};


class AIStudent:public ComputerStudent
{
public:
    AIStudent(const string& name, double *scores);
    void score(double *score_list);
protected:
    double machine_learing;
};


Student::Student(const string& n, double *scores)
{
    name = n;
    politics = scores[POLITICS];
    english = scores[ENGLISH];
}


void Student::display_name()
{
    cout<<name<<endl;
}

void Student::score(double *score_list)
{
    score_list[0] = (english+politics)/2;
    score_list[1] = score_list[0]/20;
}


ComputerStudent::ComputerStudent(const string& n, double *scores)
    : Student(n,scores)
{
    software =scores[SOFTWARE];
}

void ComputerStudent::score(double *score_list)
{
    Student::score(score_list);
    score_list[0] = (score_list[0]*2+software)/3;
    score_list[1] = software/20;
}

AIStudent::AIStudent(const string& n, double *scores)
    : ComputerStudent(n,scores)
{
    machine_learing = scores[ML];
}


void AIStudent::score(double *score_list)
{
    ComputerStudent::score(score_list);
    score_list[0] = (score_list[0]*3+machine_learing)/4;
    score_list[1] = machine_learing/20;
}


void display(Student* stu)
{
    double scores_list[2]={0,0};
    stu->display_name();
    stu->score(scores_list);
    cout<<"Average score:"<<scores_list[0]<<"GPA:"<<scores_list[1]<<endl;
}


