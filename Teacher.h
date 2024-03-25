#pragma once
#include <iostream>
#include <string>
using namespace std;


class Teacher
{
	public:
	int id;
	string name;

	Teacher() {}
	Teacher(int a, string s) : id(a), name(s) {}

	void display() const {
		cout << name << " (ID: " << id << ")";
	}
};

