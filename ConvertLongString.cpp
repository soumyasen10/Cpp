#include <bits/stdc++.h>
 
using namespace std;
string LongToString(long long_num)
{
    stack<char> stringStack;
    string signValue = "";
 
    if (long_num < 0) {
        signValue = "-";
        long_num = -long_num;
    }
 

    while (long_num > 0) {
        char convertedDigit = long_num % 10 + '0';
        stringStack.push(convertedDigit);
        long_num /= 10;
    }
 
    string long_to_string = "";
  
    while (!stringStack.empty()) {
        long_to_string += stringStack.top();
        stringStack.pop();
    }
    return signValue + long_to_string;
}
 
int main()
{
    long long_num = -10243213;
    string long_to_string = LongToString(long_num);
    cout << long_to_string;
    return 0;
}
