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

int tabulorApproch(int n, int m ,vector<vector<int>> &grid){
    vector<vector<int>> dp(n+1,vector<int>(m+1));

    for(int i = 0 ; i < n+1; i++){
        for(int j = 0  ; j < m+1; j++){
            if(i ==0 && j ==0 )
                dp[i][j] = grid[i][j];
            else{
            int up = grid[i][j], left =grid[i][j];
            if(i > 0)
            up += dp[i-1][j];
            else
                up = 1e9;
            if(j > 0)
            left += dp[i][j-1];
                else 
                    left = 1e9;
            
            dp[i][j] = min(up,left);   
            }
            
        }
    }
    return dp[n][m];
}
int spaceOpt(int n, int m ,vector<vector<int>>&grid){
vector<int> prev(m,0);
    for(int i=0; i<n ; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) temp[j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=temp[j-1];
                else left += 1e9;
                
                temp[j] = min(up,left);
            }
        }
        prev=temp;
    }
    
    return prev[m-1];
    
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int sum = 0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    
//     return memoApproch(n-1,m-1,grid,dp);
//    return tabulorApproch(n-1,m-1,grid);
    return spaceOpt(n,m,grid);
    // Write your code here.
}