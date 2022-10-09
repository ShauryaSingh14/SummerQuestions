#include <iostream>
using namespace std;
bool countStairs(int n){

    if( n == 0 )
    return true;

    if(n == 1)
    return true;

    return countStairs(n-1) && countStairs(n-2);

}
int main(){
    
    int n = 10;
    if(countStairs(n))
    cout << " Yes it's possible. " << endl;
    else 
    cout << " No we can't just. " << endl ;
    return 0;

}