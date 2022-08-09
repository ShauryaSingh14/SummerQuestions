#include <iostream>
using namespace std;
int floorLog2N(int n){
    if(n==1)
    return 0;
    return 1+ floorLog2N(n/2);
}
int main(){
    cout << floorLog2N(2);
    return 0;
}