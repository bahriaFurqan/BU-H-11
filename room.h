class Room {
public:
    string R_No;
    vector<Course> courses;

    void addCourse(const Course& c) {
        courses.push_back(c);
    }

    void display() const {
        cout << "Room Number: " << R_No << endl;
        cout << "Courses:\n";
        for (const auto& course : courses) {
            cout << "Course: " << course.name << " (Time: " << course.time << ") "
                << "Teacher: " << course.teacher.name << endl;
            cout << "Students:\n";
            for (const auto& student : course.students) {
                student.display();
                cout << endl;
            }
        }
    }
};
