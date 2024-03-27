#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Course.h"
#include "Teacher.h"
#include "Room.h"
#include "time_.h"
#include "Section.h"
#include "Student.h"

using namespace std;
class Timetable {
public:
    struct TimetableEntry {
        string day;
        course Course;
        teacher Teacher;
        room Room;
        time_ Time;
        section Section;

        TimetableEntry(string d, course c, teacher t, room r, time_ ti, section s)
            : day(d), Course(c), Teacher(t), Room(r), Time(ti), Section(s) {}
    };

    vector<TimetableEntry> entries;

    void addCourse(string d, course c, teacher t, room r, time_ ti, section s) {
        entries.push_back(TimetableEntry(d, c, t, r, ti, s));
    }

    void printTimetable() {
        for (const auto& entry : entries) {
            cout << "Day: " << entry.day << ", "
                << "Course: " << entry.Course.course_name << ", "
                << "Teacher: " << entry.Teacher.name << ", "
                << "Room: " << entry.Room.room_no << ", "
                << "Time: " << entry.Time.time_slot << ", "
                << "Section: " << entry.Section.section_name << ", "
                << "Student: " << entry.Section.Student.name << endl;
        }
    }



    void printTeacherTimetable(string teacher_name) {
        for (const auto& entry : entries) {
            if (entry.Teacher.name == teacher_name) {
                cout << "Day: " << entry.day << ", "
                    << "Course: " << entry.Course.course_name << ", "
                    << "Room: " << entry.Room.room_no << ", "
                    << "Time: " << entry.Time.time_slot << ", "
                    << "Section: " << entry.Section.section_name << ", "
                    << "Student: " << entry.Section.Student.name << endl;
            }
        }
    }

    void printSectionTimetable(string section_name) {
        for (const auto& entry : entries) {
            if (entry.Section.section_name == section_name) {
                cout << "Day: " << entry.day << ", "
                    << "Course: " << entry.Course.course_name << ", "
                    << "Teacher: " << entry.Teacher.name << ", "
                    << "Room: " << entry.Room.room_no << ", "
                    << "Time: " << entry.Time.time_slot << ", "
                    << "Student: " << entry.Section.Student.name << endl;
            }
        }
    }

    void printStudentTimetable(string student_name) {
        for (const auto& entry : entries) {
            if (entry.Section.Student.name == student_name) {
                cout << "Day: " << entry.day << ", "
                    << "Course: " << entry.Course.course_name << ", "
                    << "Teacher: " << entry.Teacher.name << ", "
                    << "Room: " << entry.Room.room_no << ", "
                    << "Time: " << entry.Time.time_slot << ", "
                    << "Section: " << entry.Section.section_name << endl;
            }
        }
    }

    void printRoomTimetable(string room_no) {
        for (const auto& entry : entries) {
            if (entry.Room.room_no == room_no) {
                cout << "Day: " << entry.day << ", "
                    << "Course: " << entry.Course.course_name << ", "
                    << "Teacher: " << entry.Teacher.name << ", "
                    << "Time: " << entry.Time.time_slot << ", "
                    << "Section: " << entry.Section.section_name << ", "
                    << "Student: " << entry.Section.Student.name << endl;
            }
        }
    }

    string getTeacherAtTime(string day, string time) {
        for (const auto& entry : entries) {
            if (entry.day == day && entry.Time.time_slot == time) {
                return entry.Teacher.name;
            }
        }
        return "No teacher found at this time.";
    }

    void printTimetableForDay(string day) {
        for (const auto& entry : entries) {
            if (entry.day == day) {
                cout << "Course: " << entry.Course.course_name << ", "
                    << "Teacher: " << entry.Teacher.name << ", "
                    << "Room: " << entry.Room.room_no << ", "
                    << "Time: " << entry.Time.time_slot << ", "
                    << "Section: " << entry.Section.section_name << ", "
                    << "Student: " << entry.Section.Student.name << endl;
            }
        }
    }

    // Function to save timetable data to a file
    void saveTimetableToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& entry : entries) {
                file << "Day: " << entry.day << ", "
                    << "Course: " << entry.Course.course_name << ", "
                    << "Teacher: " << entry.Teacher.name << ", "
                    << "Room: " << entry.Room.room_no << ", "
                    << "Time: " << entry.Time.time_slot << ", "
                    << "Section: " << entry.Section.section_name << ", "
                    << "Student: " << entry.Section.Student.name << endl;
            }
            file.close();
            cout << "Timetable data saved to file: " << filename << endl;
        }
        else {
            cout << "Unable to open file for saving timetable data: " << filename << endl;
        }
    }

    // Function to load timetable data from a file
    void loadTimetableFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            cout << "Timetable data loaded from file: " << filename << endl;
            string line;
            while (getline(file, line)) {
                cout << line << endl; // Display each line from the file
            }
            file.close();
        }
        else {
            cout << "Unable to open file: " << filename << endl;
        }
    }
};

