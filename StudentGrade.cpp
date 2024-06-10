#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    double grade1;
    double grade2;
    double grade3;

public:
    Student(const std::string& studentName, double g1, double g2, double g3) 
        : name(studentName), grade1(g1), grade2(g2), grade3(g3) {}

    double calculateAverage() const {
        return (grade1 + grade2 + grade3) / 3;
    }

 
    void display() const {
        std::cout << "Student: " << name << "\n"
                  << "Grade 1: " << grade1 << "\n"
                  << "Grade 2: " << grade2 << "\n"
                  << "Grade 3: " << grade3 << "\n"
                  << "Average Grade: " << calculateAverage() << std::endl;
    }
};

int main() {
    std::string name;
    double grade1, grade2, grade3;
    std::cout << "Enter student's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter grade for subject 1: ";
    std::cin >> grade1;

    std::cout << "Enter grade for subject 2: ";
    std::cin >> grade2;

    std::cout << "Enter grade for subject 3: ";
    std::cin >> grade3;

    Student student(name, grade1, grade2, grade3);

 
    student.display();

    return 0;
}
