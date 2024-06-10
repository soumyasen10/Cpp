#include <iostream>
#include <fstream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Default constructor
    Person() : name(""), age(0) {}

    // Parameterized constructor
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Function to set the details of the person
    void setDetails(const std::string& name, int age) {
        this->name = name;
        this->age = age;
    }

    // Function to display the details of the person
    void display() const {
        std::cout << "Name: " << name << "\nAge: " << age << std::endl;
    }

    // Function to write details to a file
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

    // Function to read details from a file
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
    // Create a person object and set details
    Person person("John Doe", 30);
    
    // Display details
    std::cout << "Original details:" << std::endl;
    person.display();
    
    // Write details to file
    person.writeToFile("person.txt");

    // Create another person object and read details from file
    Person anotherPerson;
    anotherPerson.readFromFile("person.txt");

    // Display read details
    std::cout << "\nDetails read from file:" << std::endl;
    anotherPerson.display();

    return 0;
}
