#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "course.h"
class room {
public:
    string room_no;
    vector<course> courses; // Courses assigned to the room
    room(string n) {
        room_no = n;
    }
};

