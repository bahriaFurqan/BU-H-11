#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Teacher.h"
#include "Student.h"

using namespace std;

class Course
{
public:
    string name;
    string time;
    Teacher teacher;
    vector<Student> students;

    Course() {}
    Course(const string& n, const string& t, const Teacher& te) : name(n), time(t), teacher(te) {}

    void addStudent(const Student& s) {
        students.push_back(s);
    }

    void display() const {
        cout << "Course: " << name << " (Time: " << time << ")" << endl;
        cout << "Teacher: " << teacher.name << " (ID: " << teacher.id << ")" << endl;
        cout << "Students:\n";
        for (const auto& student : students) {
            student.display();
            cout << endl;
        }
    }

};
