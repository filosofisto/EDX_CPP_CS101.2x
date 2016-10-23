#include <iostream>

using namespace std;

struct student {
    string name;
    int age;
    float marks;
};

student *initiateStudent(string, int, float);

student *highestScorer(student **stud, int totalStudents);

int main()
{
    int totalStudents = 1;
    string name;
    int age;
    float marks;

    cin >> totalStudents;

    student *stud[totalStudents];

    for(int i = 0; i < totalStudents; i++)
    {
        cin >> name >> age >> marks;

        stud[i] = initiateStudent(name,age,marks);
    }

    student *topper = highestScorer(stud,totalStudents);

    cout << topper->name << " is the topper with " << topper->marks << " marks" << endl;

    return 0;
}

student *initiateStudent(string name, int age, float marks)
{
    student *ret = new student;
    ret->name = name;
    ret->age = age;
    ret->marks = marks;

    return ret;
}

student *highestScorer(student **stud, int totalStudents)
{
    student *topper = *stud;

    for (int i = 1; i < totalStudents; i++)
    {
        stud++;

        if ((*stud)->marks > topper->marks)
            topper = *stud;
    }

    return topper;
}
