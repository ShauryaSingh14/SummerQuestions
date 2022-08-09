// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
bool checkPalindrome(string a , int i , int n){
    if( i >= n)
    return true;
    return a[i] == a[n] && checkPalindrome(a,i+1,n-1);
}
int main() {
    string s ="jsshihssj";
    int n = s.length();
    cout << checkPalindrome(s,0,n-1);
    cout << endl;
    return 0;
}