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

// Memoisation Method
int memo(int n,vector<int> &heights, vector<int>&dp){
    if(n==0){
     return 0 ;   
    }
    
    if(dp[n] != -1)
        return dp[n];
    
    int op1 = Rec(n-1,heights) + abs(heights[n]- heights[n-1]);
    if(n>1){
    int op2 = Rec(n-2,heights) +  abs(heights[n]- heights[n-2]);
    return dp[n] = min(op1,op2);     
    }
    return dp[n] = op1;
}

//Tabulor Method
int tabulor(int n, vector<int> &heights){
    vector<int> dp(n+1);
    dp[0] = 0; dp[1] = abs(heights[1]-heights[0]);
  
    for(int i = 2 ; i <= n ;i++){
        int op1 = dp[i-1] + abs(heights[i]- heights[i-1]);
        int op2 = dp[i-2] + abs(heights[i]- heights[i-2]);
        dp[i] = min(op1,op2);
    }
    return dp[n];
}

//Space Optimise Method
int SpaceOp(int n, vector<int> &heights){
    int prev2 = 0, prev = abs(heights[1]-heights[0]);
    int curr;
    for(int i =2 ; i<=n ;i++){
        int op1 = prev + abs(heights[i]- heights[i-1]);
        int op2 = prev2 + abs(heights[i]- heights[i-2]);
        curr = min(op1,op2);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
//     return Rec(n-1,heights);
    
//     return memo(n-1,heights,dp);
 //  return tabulor(n-1,heights);
   return SpaceOp(n-1,heights);
    // Write your code here.
}