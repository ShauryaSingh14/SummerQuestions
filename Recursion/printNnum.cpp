// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void printNto1(int n){
    if(n == 0)
    return ;
    cout << n << " ";
    printNto1(n-1);
}
void print1toN(int n){
    if(n==0)
    return;
    print1toN(n-1);
    cout << n << " ";
    
}
int main() {
    printNto1(5);
    cout << endl;
    print1toN(5);

    return 0;
}