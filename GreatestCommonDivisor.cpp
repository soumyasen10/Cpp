
#include <iostream> 
  
using namespace std; 
  
// Function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    int result = min(a, b); 
  
    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
  
    return result; 
} 
  
int main() 
{ 
    int a = 54, b = 33; 
  
    cout << "GCD: " << gcd(a, b); 
  
    return 0; 
}
