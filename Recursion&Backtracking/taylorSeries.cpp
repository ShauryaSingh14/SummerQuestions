// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

double Taylor(int x, int n){
    static double p = 1, f =1;
    double r;
    if(n == 0)
    return 1;
    
        r = Taylor(x,n-1);
        p = p * x; 
        f = f*n;
    return r + p/f;

}
double TaylorII(int x,int n){ // Horner's Rule

    static double s;
    if(n == 0)
    return s;
    s = 1  + x*s/n;
    return Taylor(x,n-1);
}
double TaylorIerative(int x, int n){ // Ierative Method 
    int s = 1;
    while(n--)
        s = 1 + x/n * s;
    return s;
} 
int main() {
    cout << Taylor(1,10);
    return 0;
}