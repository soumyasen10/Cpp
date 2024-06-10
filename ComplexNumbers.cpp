#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Copy constructor
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    // Overload the addition operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the multiplication operator
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Function to display the complex number
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    // Create complex numbers
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);

    // Add complex numbers
    Complex c3 = c1 + c2;
    std::cout << "Sum: ";
    c3.display();

    // Multiply complex numbers
    Complex c4 = c1 * c2;
    std::cout << "Product: ";
    c4.display();

    return 0;
}
