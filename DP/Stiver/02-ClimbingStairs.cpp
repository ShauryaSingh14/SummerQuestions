#include <bits/stdc++.h> 

int memo(int n, vector<int > &dp){
    if(n<0)
        return 0;
    if(n == 0)
        return 1;
    
    if(dp[n]!= -1)
        return dp[n];
    
    return dp[n]= memo(n-1,dp) + memo(n-2,dp);
}
int tabulor(int n, vector<int> &dp){
    dp[0] = 1;
    dp[1] = 1;
    for(int i =2 ; i<=n ;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int tabulorSpaceOp(int n){
    int prev2 = 1;
    int prev = 1;
    int curr ;
    for(int i = 2; i<=n;i++){
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs+1,-1);
//     return memo(nStairs,dp);
    return tabulor(nStairs,dp);
//     return tabulorSpaceOp(nStairs);
    //  Write your code here.
}