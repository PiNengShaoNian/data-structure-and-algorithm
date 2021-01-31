#ifndef CHAPTER_ONE_STUDNET_H
#define CHAPTER_ONE_STUDNET_H
#include <string>
#include <iostream>

using namespace std;
struct Student
{
    std::string name;
    int score;

    bool operator<(const Student &other)
    {
        return score < other.score;
    }

    friend std::ostream &operator<<(ostream &os, Student &student)
    {
        cout << student.name << " " << student.score;
        return os;
    }
};

#endif