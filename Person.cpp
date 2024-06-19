#include <iostream>
#include <fstream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person() : name(""), age(0) {}

   
    Person(const std::string& name, int age) : name(name), age(age) {}

   
    void setDetails(const std::string& name, int age) {
        this->name = name;
        this->age = age;
    }

    void display() const {
        std::cout << "Name: " << name << "\nAge: " << age << std::endl;
    }

    void writeToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << name << std::endl;
            outFile << age << std::endl;
            outFile.close();
        } else {
            std::cerr << "Unable to open file for writing." << std::endl;
        }
    }
    void readFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            std::getline(inFile, name);
            inFile >> age;
            inFile.close();
        } else {
            std::cerr << "Unable to open file for reading." << std::endl;
        }
    }
};

int main() {

    Person person("John Doe", 30);
    std::cout << "Original details:" << std::endl;
    person.display();
  
    person.writeToFile("person.txt");


    Person anotherPerson;
    anotherPerson.readFromFile("person.txt");

    std::cout << "\nDetails read from file:" << std::endl;
    anotherPerson.display();

    return 0;
}
