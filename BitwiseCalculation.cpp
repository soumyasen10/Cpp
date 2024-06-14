#include <iostream>
using namespace std;
/*
 * class declaration
 */
class bitwise_operator {
public:
 
    void bitwise_and(int a, int b)
    {
        cout << "a & b = " << (a & b) << "\n";
    }
    // function for bitwise OR
    void bitwise_or(int a, int b)
    {
        cout << "a | b = " << (a | b) << "\n";
    }
    // function for bitwise XOR
    void bitwise_xor(int a, int b)
    {
        cout << "a ^ b = " << (a ^ b) << "\n";
    }
    // function for bitwise NOT
    void bitwise_not(int a, int b)
    {
        cout << "~a = " << (~a) << "\n";
        cout << "~b = " << (~b) << "\n";
    }
    // function for bitwise Left Shift
    void bitwise_leftshift(int a, int b)
    {
        cout << "a << b = " << (a << b) << "\n";
    }
    // function for bitwise Right Shift
    void bitwise_rightshift(int a, int b)
    {
        cout << "a >> b = " << (a >> b) << "\n";
    }
};
/*
 * Main Function
 */
int main()
{
    int a, b, option;
    char choice;
    bitwise_operator o;
    do {
        cout << "Enter the value of a and b:\n";
        cin >> a >> b;
        cout << "\nBITWISE OPERATION:\n";
        cout << "1.AND\n";
        cout << "2.OR\n";
        cout << "3.XOR\n";
        cout << "4.NOT\n";
        cout << "5.Left Shift\n";
        cout << "6.Right Shift\n";
        cout << "Select your option:\n";
        cin >> option;
        switch (option) {
        case 1:
            o.bitwise_and(a, b);
            break;
        case 2:
            o.bitwise_or(a, b);
            break;
        case 3:
            o.bitwise_xor(a, b);
            break;
        case 4:
            o.bitwise_not(a, b);
            break;
        case 5:
            o.bitwise_leftshift(a, b);
            break;
        case 6:
            o.bitwise_rightshift(a, b);
            break;
        defualt:
            cout << "Invalid option:\n";
        }
        cout << "\nDo you want to continue?(y/n)";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    return 0;
}
