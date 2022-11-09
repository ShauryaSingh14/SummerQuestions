#include <bits/stdc++.h> 

int Rec(int n, vector<int>&heights){
    if(n==0)
        return 0;
    int op1 = Rec(n-1,heights) + abs(heights[n]- heights[n-1]);
    if(n>1){
    int op2 = Rec(n-2,heights) +  abs(heights[n]- heights[n-2]);
    return min(op1,op2);     
    }
    return op1;
}

int memo(int n,vector<int> &heights, vector<int>&dp){
    if(n==0){
     return 0 ;   
    }
    
    if(dp[n] != -1)
        return dp[n];
    
    int op1 = dp[n-1] + abs(heights[n]- heights[n-1]);
    if(n>1){
    int op2 = dp[n-2] +  abs(heights[n]- heights[n-2]);
    return dp[n] = min(op1,op2);     
    }
    return dp[n] = op1;
    
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
//     return Rec(n-1,heights);
    return memo(n-1,heights,dp);
    // Write your code here.
}