#include <bits/stdc++.h> 
int memoApproch(int m , int n, 
                vector<vector<int>> &dp){
     if(m == 0  && n== 0)
            return 1;
    if(m < 0 || n < 0 ){
        return 0;
    }
    
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    int right = memoApproch(m-1,n,dp);
    int bottom = memoApproch(m,n-1,dp);
    
    return dp[m][n] = right + bottom;
}
int tabulorApproch(int m, int n){
    vector<vector<int>> dp(m +1,vector<int>(n+1));
//Self Code 
    for(int i = 0 ; i< m+1 ;i++){
        for(int j =0 ;j < n+1 ;j++){
            if(i == 0 || j== 0 )
                dp[i][j] = 1;
        }
    }
    
    for(int i = 1; i < m +1 ;i++){
        for(int j = 1; j< n+1 ;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
}

int spaceOpt(int m,int n){
    //self Code
 vector<int> prev(n+1,1);
 vector<int> curr(n+1,1);
    
    for(int i = 1; i < m +1 ;i++){
        for(int j = 1; j< n+1 ;j++){
            curr[j] = prev[j] + curr[j-1];
            prev[j] = curr[j];
        }
    }
    return prev[n];
}


int uniquePaths(int m, int n) {
//     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
// 	return memoApproch(m-1,n-1,dp);
//     return tabulorApproch(m-1,n-1);
    return spaceOpt(m-1,n-1);
}