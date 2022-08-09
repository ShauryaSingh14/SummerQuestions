// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int sumOfDigits(int n){
    if( n == 0)
    return n;
    return n%10 + sumOfDigits(n/10);
}
int sumOfDigitsTailRec(int n ,int sum){
    if( n == 0)
    return sum;
    return sumOfDigitsTailRec(n/10,sum + n%10);
}
int main() {
    cout << sumOfDigits(253);
    cout << endl;
    cout << sumOfDigitsTailRec(253,0);
    return 0;
}