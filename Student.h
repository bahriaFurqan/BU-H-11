#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "person.h"
class student : public person {
public:
    string enrollment;
    student(string n, string en) : person(n) {
        enrollment = en;
    }
};

