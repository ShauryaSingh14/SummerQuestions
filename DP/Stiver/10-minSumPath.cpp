#include <bits/stdc++.h> 

int memoApproch(int n ,int m,vector<vector<int>> &grid,
               vector<vector<int>> &dp){
    if(n == 0 && m == 0){
        return grid[n][m];
    }
    if(n < 0 || m < 0){
        return 1e9;
    }
    
    if(dp[n][m] != -1)
        return dp[n][m];
    
    int up = grid[n][m] + memoApproch(n-1,m,grid,dp);
    int left = grid[n][m] + memoApproch(n,m-1,grid,dp);
    
    return dp[n][m]= min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int sum = 0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    
    return memoApproch(n-1,m-1,grid,dp);
    // Write your code here.
}