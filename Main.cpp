int main() {
    srand(time(0)); // seed the random number generator

    Timetable timetable;
    vector<time_> timeslots = {
       time_("Monday", "9:00 - 10:00"),
       time_("Tuesday", "10:00 - 11:00"),
       time_("Wednesday", "11:00 - 12:00"),
       time_("Thursday", "12:00 - 1:00"),
       time_("Friday", "1:00 - 2:00"),
    };

    // Timetable timetable;


    vector<course> courses = {
        course("Math"),
        course("Science"),
        course("History"),
        course("English"),
        course("Computer Science"),
    };
    vector<teacher> teachers = {
        teacher("Mr. Waleed", "1"),
        teacher("Mrs. Zeeshan", "2"),
        teacher("Mr. Tamim", "3"),
        teacher("Mrs. Adeel", "4"),
        teacher("Mr. Sami", "5"),
    };
    vector<room> rooms = {
        room("4-15"),
        room("4-16"),
        room("4-17"),
        room("4-02"),
        room("4-01"),
    };

    vector<section> sections = {
        section("A", student("Ali", "1")),
        section("B", student("Ahmed", "2")),
        section("C", student("Asad", "3")),
        section("D", student("Ahsan", "4")),
        section("E", student("Adeel", "5")),
    };


    for (;;) {
        int option;
        cout << "1. Generate timetable" << endl;
        cout << "2. Print timetable" << endl;
        cout << "3. Print timetable for a specific day" << endl;
        cout << "4. Print timetable for a specific teacher" << endl;
        cout << "5. Print timetable for a specific section" << endl;
        cout << "6. Print timetable for a specific room" << endl;
        cout << "7. Save timetable to file" << endl;
        cout << "8. Load timetable from file" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter option: ";

        cin >> option;

        if (option == 1) {
            for (int i = 0; i < 10; i++) {
                // Randomly select a course, teacher, room, time slot, and section
                course c = courses[rand() % courses.size()];
                teacher t = teachers[rand() % teachers.size()];
                room r = rooms[rand() % rooms.size()];
                time_ ti = timeslots[rand() % timeslots.size()];
                section s = sections[rand() % sections.size()];

                timetable.addCourse(ti.day, c, t, r, ti, s);
            }
        }

        else if (option == 2) {
            system("cls");
            timetable.printTimetable();
        }
        else if (option == 3) {
            string day;
            for (;;) {
                cout << "Enter day: ";
                cin >> day;
                if (day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday" || day == "Friday") {
                    break;
                }
                else {
                    cout << "Invalid day. Please enter a valid day." << endl;
                }
            }
            system("cls");
            timetable.printTimetableForDay(day);
        }
        else if (option == 4) {
            string teacher_name;
            cout << "Enter teacher name: ";
            cin.ignore(); // Ignore previous newline character
            getline(cin, teacher_name);
            system("cls");
            timetable.printTeacherTimetable(teacher_name);
        }
        else if (option == 5) {
            string section_name;
            cout << "Enter section name: ";
            cin >> section_name;
            system("cls");
            timetable.printSectionTimetable(section_name);
        }
        else if (option == 6) {
            string room_no;
            cout << "Enter room number: ";
            cin >> room_no;
            system("cls");
            timetable.printRoomTimetable(room_no);
        }
        else if (option == 7) {
            system("cls");
            timetable.saveTimetableToFile("timetable_data.txt");
        }
        else if (option == 8) {
            system("cls");
            timetable.loadTimetableFromFile("timetable_data.txt");
        }
        else if (option == 9) {
            break;
        }
        else {
            cout << "Invalid option. Please enter a valid option." << endl;
        }
    }

    return 0;
}
