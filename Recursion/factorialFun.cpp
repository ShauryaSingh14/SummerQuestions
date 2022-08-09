// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int factorialNonTailRec(int n){
    
    if(n == 0 || n == 1)
    return 1;
    return n * factorialNonTailRec(n-1);
}
int factorialTailRec(int n, int res){
    if(n == 0 || n ==1)
    return res;
    factorialTailRec(n-1, res*n);
}
int main() {
    cout << factorialNonTailRec(2);
    cout << endl;
    cout << factorialTailRec(2,1);

    return 0;
}