#include <iostream>
#include <vector>
using namespace std;
// NOT All testcases passes.
int sqrtN(long long int N)
{
    long long int s = 0;
    long long int e = N;
    int ans;
    while(s<=e){
        int mid = s + (e-s)/2;
        if( mid*mid == N )
            return mid;
        else if(mid*mid < N ){
          s = mid + 1;
          ans = mid;
        }
        else
            e = mid - 1;
    }
    return ans;
}
int main() {
    cout << sqrtN(65) << endl;
    return 0;
}