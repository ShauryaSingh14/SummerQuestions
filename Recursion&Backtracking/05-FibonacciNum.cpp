// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int Fibonacci(int n){
    if(n == 0 || n ==1)
    return n;
    return Fibonacci(n-1) + Fibonacci(n-2);
}
int FibonacciTailRec(int n,int a ,int b){
    if(n== 0)
    return a;
    if(n == 1) 
    return b;
    return FibonacciTailRec(n-1,b,a+b);
}
int main() {
    cout << FibonacciTailRec(4,0,1);
    return 0;
}