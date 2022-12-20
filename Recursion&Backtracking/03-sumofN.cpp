// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int SumofNnums(int n){
    if(n == 0)
    return 0;
    return n + SumofNnums(n-1);
}
int SumofNnumsTailRec(int n,int res){
    if(n== 0){
    return res;
    }
    return SumofNnumsTailRec(n-1, res + n);
}
int sumofNFormula(int n){
    return n*(n+1)/2;
}
int main() {
    cout << SumofNnums(5);
    cout << endl;
    cout << SumofNnumsTailRec(5,0);
    cout << endl;
    cout << sumofNFormula(5);
    return 0;
}