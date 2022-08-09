// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void printN(int n){
    if(n == 0)
    return ;
    cout << n << " ";
    printN(n-1);
}
int main() {
    printN(5);

    return 0;
}