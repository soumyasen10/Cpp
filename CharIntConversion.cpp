#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() 
{
    stringstream string; 
    string << "5"; 
    int n; 
    string >> n;
    cout << "Integer value is: " << n;
    return 0;
}
