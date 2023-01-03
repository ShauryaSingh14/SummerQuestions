#include <bits/stdc++.h> 
int memoApproch(int n,vector<int> nums, vector<int> &dp){
    if(n == 0)
        return nums[n];
    if(n<0)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];
    
    int pick = nums[n] + memoApproch(n-2,nums,dp);
    int notPick = memoApproch(n-1,nums,dp);
    
    return dp[n] = max(pick,notPick);
}
int tabulorApproch(int n, vector<int> nums,vector<int>&dp){
    dp[0] = nums[0];
    
    for(int i = 1 ; i< n+1; i++){
        int pick = nums[i];
       
        if(i-2 >= 0) // for handling negtive idxs
           pick+=dp[i-2];
        
        int notPick = dp[i-1];
        
        dp[i] = max(pick,notPick);
    }
    return dp[n];
}
int spaceOpt(int n ,vector<int> nums){
    int prev2 = 0;
    int prev = nums[0];
    
    for(int i = 1 ; i< n+1; i++){
        int pick = nums[i] + prev2;
        int notPick = prev;
        
        prev2 = prev;
        prev = max(pick,notPick);
    }
    return prev;
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+2,-1);
//     return memoApproch(n-1,nums,dp); // O(n)|| O(n) + recur call Space
//     return tabulorApproch(n-1,nums,dp); // O(n) || O(n)
       return spaceOpt(n-1,nums); //O(n)|| O(1)
}