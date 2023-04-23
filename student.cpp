#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

typedef enum
{
    EXCELLENT,
    GOOD,
    UNDER_GOOD,
    BAD
}Rank;

class student
{
    private:
        int id;
        char name[20];
        char sex[5];
        int age;
        int math_score;
        int phy_score;
        int chem_score;
    public:
        void input();
        void output();
        float average_score();
        Rank Rank_cal();
    friend class menu;

};

void student::input()
{
    cout<<"Enter student's id : ";cin>>id;
    cout<<"Enter student's name : ";fflush(stdin);gets(name);
    cout<<"Enter student's sex : ";fflush(stdin);gets(sex);
    cout<<"Enter student's age : ";cin>>age;
    cout<<"Enter student's math score : ";cin>>math_score;
    cout<<"Enter student's physic score : ";cin>>phy_score;
    cout<<"Enter student's chemistry score : ";cin>>chem_score;
    
}
void student::output()
{
    float average = average_score();
    Rank rak = Rank_cal();
    cout<<setw(10)<<id<<setw(20)<<name<<setw(5)<<age<<setw(5)<<math_score<<setw(5)<<phy_score<<setw(5)<<chem_score<<setw(5)<<average<<setw(15)<<rak<<endl;
}
float student::average_score()
{
    return (math_score + phy_score + chem_score)/3;
}

Rank student::Rank_cal()
{
    if(average_score()>=8) return EXCELLENT;
    else if (average_score()>=6.5) return GOOD;
    else if (average_score()>=5) return UNDER_GOOD;
    else return BAD;
}

class menu
{
private:
    student a[10];
    int n;
public:
    void input();
    void studentAdd();
    void studentUpdate();
    void studentDelete();
    void studentSearch();
    void studentSoftGPA();
    void studentSoftNAME();
    void studentDisplay();
};
void menu::input()
{
    cout<<"Enter number of student : ";cin>>n;
    // a = new student[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter infor of students "<<i+1<<endl;
        a[i].input();
    }
}
void menu::studentAdd()
{
    student k;
    k.input();
    a[n] = k;
    n++;
}
void menu::studentUpdate()
{
    int id;
    cout<<"Enter student id you want to change : ";cin>>id;
    for(int i=0;i<n;i++)
    {
        if(a[i].id == id)
        {
            a[i].input();
        }
    }
}
void menu::studentDelete()
{
    int id;
    cout<<"Enter student id you want to delete : ";cin>>id;
    for(int i=0;i<n;i++)
    {
        if(a[i].id == id)
        {
            for(int j = i;j<n;j++)
            {
                a[j] = a[j+1];
            }
            n--;
        }
    }
}
void menu::studentSearch()
{
    char _name[20];
    cout<<"Enter name : ";fflush(stdin);gets(_name);
    for(int i=0;i<n;i++)
    {
        if(strcmp(_name,a[i].name)==0)
        {
            cout<<"Infor student name "<<_name<<": "<<endl;
            a[i].output();
        }
    }
}

void menu::studentSoftGPA()
{
    for(int i=0;i<n;i++)
    {
        float avera_b = a[i].average_score();
        for(int j=i+1;j<n;j++)
        {
            float avera_a = a[j].average_score();
            if(avera_b>avera_a)
            {
                student tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
}
void menu::studentSoftNAME()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(a[i].name,a[j].name)>0)
            {
                student tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
}

void menu::studentDisplay()
{
    cout<<setw(10)<<"id"<<setw(20)<<"name"<<setw(5)<<"age"<<setw(5)<<"math"<<setw(5)<<"phy"<<setw(5)<<"chem"<<setw(5)<<"aver"<<setw(15)<<"Rank"<<endl;
    for(int i=0;i<n;i++)
    {
        a[i].output();
    }
}

int main()
{
    
    menu b;
    
    b.input();
    b.studentDisplay();

   
    // b.studentAdd();
    // b.studentDisplay();

    // b.studentUpdate();
    // b.studentDisplay();

    // b.studentDelete();
    // b.studentDisplay();

    // b.studentSearch();

    b.studentSoftGPA();
    cout<<"After softing by GPA"<<endl;
    b.studentDisplay();

    b.studentSoftNAME();
    cout<<"After softing by NAME"<<endl;
    b.studentDisplay();

}