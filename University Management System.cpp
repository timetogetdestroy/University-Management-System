#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Person
{
    string name;

public:
    Person(string name)
    {
        this->name = name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
};
class Student : public Person
{
private:
    int StudentID;
    string Name;
    string DOB;
    string Contact;
    vector<string> enrolledCourses;
    map<string, int> grades;

public:
    void setStudentID(int studentID)
    {
        StudentID = studentID;
    }
    int getStudentID()
    {
        return StudentID;
    }

    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }

    void setDOB(string dob)
    {
        DOB = dob;
    }
    string getDOB()
    {
        return DOB;
    }

    void setContact(string contact)
    {
        Contact = contact;
    }
    string getContact()
    {
        return Contact;
    }

    Student(int id, string name, string dob, string contact) : Person(name)
    {
        StudentID = id;
        DOB = dob;
        Contact = contact;
    }

    void StudentInfo()
    {
        cout << "StudentID: " << StudentID << endl;
        cout << "Name: " << Name << endl;
        cout << "DOB: " << DOB << endl;
        cout << "Contact: " << Contact << endl;
    }

    void enrollCourse(string course)
    {
        enrolledCourses.push_back(course);
        cout << "Enrolled in " << course << " successfully." << endl;
    }

    void dropCourse(string course)
    {
        for (int i = 0; i < enrolledCourses.size(); i++)
        {
            if (enrolledCourses[i] == course)
            {
                enrolledCourses.erase(enrolledCourses.begin() + i);
                cout << "Dropped " << course << " successfully." << endl;
                return;
            }
        }
        cout << Name << " You are not enrolled in " << course << "." << endl;
    }

    void viewEnrolledCourses()
    {
        cout << "Enrolled Courses: ";
        for (int i = 0; i < enrolledCourses.size(); i++)
        {
            cout << enrolledCourses[i] << " ";
        }
        cout << endl;
    }

    void assignGrade(string course, int grade)
    {
        grades[course] = grade;
        cout << "Assigned grade " << grade << " to " << course << " for " << Name << "." << endl;
    }

    void viewGrades()
    {
        cout << Name << "'s Grades:" << endl;
        for (auto const &grade : grades)
        {
            cout << "Course: " << grade.first << ", Grade: " << grade.second << endl;
        }
    }
    int getCurrentSemester()
    {
        // Implement a method to get the current semester based on DOB or other factors.
        // For simplicity, we return a static value in this example.
        static int semester = 1;
        return semester;
    }
    void generateTranscript()
    {
        cout << "Transcript for " << Name << ":" << endl;
        cout << "Student ID: " << StudentID << ", Semester: " << getCurrentSemester() << endl;
        cout << "Enrolled Courses: ";
        for (const auto &course : enrolledCourses)
        {
            cout << course << " ";
        }
        cout << endl;
        cout << "Grades:" << endl;
        for (const auto &grade : grades)
        {
            cout << "Course: " << grade.first << ", Grade: " << grade.second << endl;
        }
    }

    void filterTranscripts(vector<Student> &student, int studentID, int semester)
    {
        for (auto &student : student)
        {
            if (student.getStudentID() == studentID && student.getCurrentSemester() == semester)
            {
                student.generateTranscript();
            }
        }
    }
};

class Course
{
private:
    int CourseCode;
    string CourseTitle;
    string Instructor;
    int MaxCapacity;

protected: // Make it protected
    vector<Student> students;

public:
    void setCourseCode(int courseCode)
    {
        CourseCode = courseCode;
    }

    int getCourseCode()
    {
        return CourseCode;
    }

    void setCourseTitle(string courseTitle)
    {
        CourseTitle = courseTitle;
    }

    string getCourseTitle()
    {
        return CourseTitle;
    }

    void setInstructor(string instructor)
    {
        Instructor = instructor;
    }

    string getInstructor()
    {
        return Instructor;
    }

    void setMaxCapacity(int maxCapacity)
    {
        MaxCapacity = maxCapacity;
    }

    int getMaxCapacity()
    {
        return MaxCapacity;
    }

    Course(int courseCode, string courseTitle, string instructor, int maxCapacity)
    {
        CourseCode = courseCode;
        CourseTitle = courseTitle;
        Instructor = instructor;
        MaxCapacity = maxCapacity;
    }

    void CourseDetails()
    {
        cout << "CourseCode: " << CourseCode << endl;
        cout << "CourseTitle: " << CourseTitle << endl;
        cout << "Instructor: " << Instructor << endl;
        cout << "MaxCapacity: " << MaxCapacity << endl;
    }

    void addStudent(Student student)
    {
        if (students.size() < MaxCapacity)
        {
            students.push_back(student);
            cout << student.getName() << " added successfully!" << endl;
        }
        else
        {
            cout << "Course is full. Cannot add student." << endl;
        }
    }

    void removeStudent(int studentID)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getStudentID() == studentID)
            {
                students.erase(students.begin() + i);
                cout << "Student removed successfully!" << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void displayStudents()
    {
        cout << "Enrolled Students:" << endl;
        for (int i = 0; i < students.size(); i++)
        {
            cout << "Student ID: " << students[i].getStudentID() << ", Student Name: " << students[i].getName() << endl;
        }
    }

    void assignGrade(Student &student, string course, int grade)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getStudentID() == student.getStudentID())
            {
                students[i].assignGrade(course, grade);
                return;
            }
        }
        cout << student.getName() << " is not enrolled in this course." << endl;
    }
};

class Instructor : public Person
{
private:
    int InstructorID;
    string InstructorName;
    string InstructorContact;
    vector<Course> courses;

public:
    void setInstructorID(int instructorID)
    {
        InstructorID = instructorID;
    }
    int getInstructorID()
    {
        return InstructorID;
    }

    void setInstructorName(string instructorName)
    {
        InstructorName = instructorName;
    }
    string getInstructorName()
    {
        return InstructorName;
    }

    void setInstructorContact(string instructorContact)
    {
        InstructorContact = instructorContact;
    }
    string getInstructorContact()
    {
        return InstructorContact;
    }

    Instructor(int instructorID, string instructorName, string instructorContact) : Person(instructorName)
    {
        InstructorID = instructorID;
        InstructorName = instructorName;
        InstructorContact = instructorContact;
    }

    void InstructorDetail()
    {
        cout << "InstructorID: " << InstructorID << endl;
        cout << "InstructorName: " << InstructorName << endl;
        cout << "InstructorContact: " << InstructorContact << endl;
    }

    void assignCourse(Course course)
    {
        courses.push_back(course);
        cout << "Course " << course.getCourseTitle() << " assigned to " << InstructorName << " successfully." << endl;
    }

    void displayCourses()
    {
        cout << "Courses taught by " << InstructorName << ":" << endl;
        for (int i = 0; i < courses.size(); i++)
        {
            cout << "Course Title: " << courses[i].getCourseTitle() << endl;
        }
    }
};

class SpecialCourse : public Course
{

public:
    SpecialCourse(int courseCode, string courseTitle, string instructor, int maxCapacity)
        : Course(courseCode, courseTitle, instructor, maxCapacity)
    {
        // constructor body
    }

    void addStudent(Student student)
    {
        if (getMaxCapacity() == 0)
        {
            cout << "Invalid maximum capacity." << endl;
            return;
        }

        if (students.size() >= getMaxCapacity())
        {
            cout << "Cannot enroll " << student.getName() << ". The course is at full capacity." << endl;
        }
        else
        {
            Course::addStudent(student);
        }
    }
};
void displayMenu()
{
    cout << "----- Menu -----\n";
    cout << "1. View Student Information\n";
    cout << "2. Enroll in a Course\n";
    cout << "3. View Enrolled Courses\n";
    cout << "4. Drop a Course\n";
    cout << "5. View Grades\n";
    cout << "6. Filter Transcripts\n";
    cout << "7. View Course Details\n";
    cout << "8. Add Student to a Course\n";
    cout << "9. Assign Grade to Student\n";
    cout << "10. View Instructor Details\n";
    cout << "11. Assign Course to Instructor\n";
    cout << "12. View Special Course Details\n";
    cout << "13. Exit\n";
}
void Driver()
{

    Student student1(4526, "Eddy", "October 20, 2003", "Ilamdeen702@gmail.com");
    Student student2(2326, "Fiza", "May 10, 2003", "Fiza@gmail.com");
    Student student3(1002, "Urwa", "October 2, 2003", "Urwa702@gmail.com");

    Course OOP(1248, "Object Oriented Programming", "Sehrish Munawwar", 50);
    Course DLD(1249, "Digital Logic Design", "Ali Ahmad", 50);
    Course PF(1148, "Programming Fundamentals", "Ali Ahmad", 50);
    Course course2(809, "Data Structures", "Ali Ahmed", 40);
    Course course3(110, "Discrete Structures", "Samra Kanwal", 60);

    Instructor instructor1(1, "Sehrish Munawar", "sehrish@gmail.com");
    Instructor instructor2(2, "Ali Ahmed", "ali@gmail.com");

    SpecialCourse specialCourse(1010, "English", "Zahra Fatima", 50);

    vector<Student> students = {student1, student2, student3};

    int choice = -1;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter student ID: ";
            int id;
            cin >> id;
            if (id == student1.getStudentID())
                student1.StudentInfo();
            else if (id == student2.getStudentID())
                student2.StudentInfo();
            else if (id == student3.getStudentID())
                student3.StudentInfo();
            else
                cout << "Student not found.\n";
            break;
        }
        case 2:
        {
            cout << "Enter student ID and course ID to enroll: ";
            int studentID, courseID;
            cin >> studentID >> courseID;
            if (studentID == student1.getStudentID())
            {
                if (courseID == OOP.getCourseCode())
                    student1.enrollCourse("OOP");
                else if (courseID == DLD.getCourseCode())
                    student1.enrollCourse("DLD");
                else if (courseID == PF.getCourseCode())
                    student1.enrollCourse("PF");
                else
                    cout << "Course not found.\n";
            }
            if (studentID == student2.getStudentID())
            {
                if (courseID == OOP.getCourseCode())
                    student1.enrollCourse("OOP");
                else if (courseID == DLD.getCourseCode())
                    student1.enrollCourse("DLD");
                else if (courseID == PF.getCourseCode())
                    student1.enrollCourse("PF");
                else
                    cout << "Course not found.\n";
            }
            if (studentID == student3.getStudentID())
            {
                if (courseID == OOP.getCourseCode())
                    student1.enrollCourse("OOP");
                else if (courseID == DLD.getCourseCode())
                    student1.enrollCourse("DLD");
                else if (courseID == PF.getCourseCode())
                    student1.enrollCourse("PF");
                else
                    cout << "Course not found.\n";
            }
            else
            {
                cout << "Invalid Student ID\n";
            }
            break;
        }
        case 3:
        {
            cout << "Enter student ID to view enrolled courses: ";
            int id;
            cin >> id;
            if (id == student1.getStudentID())
                student1.viewEnrolledCourses();
            else if (id == student2.getStudentID())
                student2.viewEnrolledCourses();
            else if (id == student3.getStudentID())
                student3.viewEnrolledCourses();
            else
                cout << "Student not found.\n";
            break;
        }
        case 4:
        {
            cout << "Enter student ID and course ID to drop: ";
            int studentID, courseID;
            cin >> studentID >> courseID;
            if (studentID == student2.getStudentID() && courseID == PF.getCourseCode())
                student2.dropCourse("PF");
            // Add other cases if needed
            break;
        }
        case 5:
        {
            cout << "Enter student ID to view grades: ";
            int id;
            cin >> id;
            if (id == student1.getStudentID())
                student1.viewGrades();
            else if (id == student2.getStudentID())
                student2.viewGrades();
            break;
        }
        case 6:
        {
            cout << "Enter student ID to filter transcripts: ";
            int id;
            cin >> id;
            if (id == student1.getStudentID())
                student1.filterTranscripts(students, student1.getStudentID(), student1.getCurrentSemester());
            else if (id == student2.getStudentID())
                student2.filterTranscripts(students, student2.getStudentID(), student2.getCurrentSemester());
            break;
        }
        case 7:
        {
            cout << "Enter course ID to view details: ";
            int courseID;
            cin >> courseID;
            if (courseID == OOP.getCourseCode())
                OOP.CourseDetails();
            else if (courseID == course2.getCourseCode())
                course2.CourseDetails();
            else if (courseID == course3.getCourseCode())
                course3.CourseDetails();
            break;
        }
        case 8:
        {
            cout << "Enter course ID and student ID to add: ";
            int courseID, studentID;
            cin >> courseID >> studentID;
            if (courseID == OOP.getCourseCode() && studentID == student1.getStudentID())
                OOP.addStudent(student1);
            else if (courseID == course2.getCourseCode() && studentID == student2.getStudentID())
                course2.addStudent(student2);
            else if (courseID == course3.getCourseCode() && studentID == student3.getStudentID())
                course3.addStudent(student3);
            break;
        }
        case 9:
        {
            cout << "Enter course ID, student ID, and grade to assign: ";
            int courseID, studentID;
            int grade;
            cin >> courseID >> studentID >> grade;
            if (courseID == OOP.getCourseCode() && studentID == student1.getStudentID())
                OOP.assignGrade(student1, "OOP", grade);
            else if (courseID == course2.getCourseCode() && studentID == student2.getStudentID())
                course2.assignGrade(student2, "DLD", grade);
            break;
        }
        case 10:
        {
            cout << "Enter instructor ID to view details: ";
            int id;
            cin >> id;
            if (id == instructor1.getInstructorID())
                instructor1.InstructorDetail();
            else if (id == instructor2.getInstructorID())
                instructor2.InstructorDetail();
            break;
        }
        case 11:
        {
            cout << "Enter instructor ID and course ID to assign: ";
            int instructorID, courseID;
            cin >> instructorID >> courseID;
            if (instructorID == instructor1.getInstructorID() && courseID == OOP.getCourseCode())
                instructor1.assignCourse(OOP);
            else if (instructorID == instructor2.getInstructorID() && courseID == course2.getCourseCode())
                instructor2.assignCourse(course2);
            break;
        }
        case 12:
        {
            cout << "Special Course Details:\n";
            specialCourse.CourseDetails();
            specialCourse.displayStudents();
            break;
        }
        case 13:
        {
            cout << "Exiting...\n";
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again.\n";
        }
        }
    } while (choice != 13);
}
int main()
{
    Driver();
    return 0;
}
