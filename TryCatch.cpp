#include <iostream>
#include <limits>
using namespace std;
 
typedef numeric_limits<char> numlim;
void to_char(int i)
{
    try
    {
        if (i < numlim::min() || i > numlim::max())
            throw 1; // error code 1
        else
        {
            cout << "The char value for " << i << " is \'"
                 << static_cast<char>(i) << "\'" << endl;
 
            return;
        }
 
    }
    catch(int error)
    {
        // execute following if error == 1
        if (error == 1)
        {
            cout << "Range Error : exceeding character limits"
                 << endl;
        }
    }
}
 
int main()
{
    int i;
 
    cout << "Enter a value ";
    cin >> i;
    to_char(i);
}
