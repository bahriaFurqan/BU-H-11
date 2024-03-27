#pragma once
#include <iostream>
#include <string>
    
using namespace std;
#include "student.h"

class section {
public:
    string section_name;
    student Student;
    section(string n, student s) : section_name(n), Student(s) {}
};

