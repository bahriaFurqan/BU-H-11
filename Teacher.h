#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "person.h"
class teacher : public person {
public:
    string teacher_id;
    teacher(string n, string id) : person(n) {
        teacher_id = id;
    }
};

