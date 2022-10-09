#include <iostream>
using namespace std;
int countDistinctWays(int nStairs) {
    if(nStairs < 0)
        return 0;
    if(nStairs == 0)
        return 1;
    else{
        return countDistinctWays(nStairs-1)+ countDistinctWays(nStairs-2);
    }
}
int main(){
    return 0;
}