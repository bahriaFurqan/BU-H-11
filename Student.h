#pragma once
#include <iostream>
#include <string>
using namespace std;


class Student
{
public:
    int enroll;
    string name;

    Student() {}
    Student(int a, string s) : enroll(a), name(s) {}

    void display() const {
        cout << name << " (Enroll: " << enroll << ")";
    }
};

