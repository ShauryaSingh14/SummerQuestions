#include <iostream>
using namespace std;
void binaryEqivalent(int n ){
    if(n == 0)
    return;
    binaryEqivalent(n/2);
    cout << n%2<<" ";
}
int main(){
    cout << "THE Binary Eqvialent of 7 is ";
    binaryEqivalent(7);
    return 0;
}