//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  // Memoisation Method  
  solve(long long n, vector<long long int> &dp){
    if(n<= 0)
    return n;

    if(dp[n] != -1 )
    return dp[n];

    return dp[n] = solve(n,dp); 
  }
long long int nthFibonacciII(long long int n){
    vector<int> dp(n+1,-1);
    solve(n,dp);
    return dp[n];
}
  //Tableuation Method  
  long long int nthFibonacciII(long long int n){
    vector<long long int > dp(n+1);
     dp[0] = 0 ; dp[1] = 1;

     for(int i = 2; i<=n ;i++){
        dp[i] = dp[i-1] + dp[i-2];
     }
     return dp[n];
  }
  // Space optimise Soluation
    long long int nthFibonacci(long long int n){
        int prev2 = 0, prev =1;
        int curr ;
        for(int i = 2 ; i <= n ;i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends