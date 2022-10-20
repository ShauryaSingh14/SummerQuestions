// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
void subSets(string s, string curr , int idx){
    if( idx == s.length())
    {
        cout << curr << " ";
        return;
    }
    subSets(s,curr,idx+1);
    subSets(s,curr + s[idx],idx+1);
}
int main() {
    
    string s = "ABC";
    subSets(s,"",0);
    cout << endl;
    return 0;
}