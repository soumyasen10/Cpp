#include <bits/stdc++.h> 
using namespace std; 
 
// driver code 
int main() 
{ 
    fstream file; 
 
    ifstream ifile("file.txt", ios::in); 

    ofstream ofile("file2.txt", ios::out | ios::app); 
 
 
    if (!ifile.is_open()) { 
        cout << "file not found"; 
    } 
    else { 
        ofile << ifile.rdbuf(); 
    } 
    string word; 

    file.open("file2.txt");
    while (file >> word) {
        cout << word << " "; 
    } 
 
    return 0; 
} 
