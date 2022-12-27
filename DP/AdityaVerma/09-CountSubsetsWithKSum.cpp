#include <bits/stdc++.h> 

//array having non zero/negative values 
int CountRec(vector<int> arr,int n,int w){
    if( n == 0){
        if(w == 0)
        return 1;
        
        return 0;
    }
    
    if(arr[n-1] <= w ){
    return CountRec(arr,n-1,w-arr[n-1]) + CountRec(arr,n-1,w);
    }
    else{
    return CountRec(arr,n-1,w);
    }
}

int CountMemo(vector<int> arr,int n, int w, vector<vector<int>> &dp){
    if( n == 0){
        if(w == 0)
        return 1;
        
        return 0;
    }
    
    if(dp[n][w] != -1)
        return dp[n][w];
    
    if(arr[n-1] <= w ){
    return dp[n][w] = CountRec(arr,n-1,w-arr[n-1]) + CountRec(arr,n-1,w);
    }
    else{
    return dp[n][w] = CountRec(arr,n-1,w);
    }
}

int CountTabulor(vector<int> arr,int n, int w, vector<vector<int>> &dp){
    
    for(int i =0 ; i<= n; i++){
        for(int j =0 ; j<=w+1;j++){
            if(j==0)
            dp[i][j] = 1;
        }       
    }
    
    for(int i = 1; i<= n ;i++){
        for(int j = 1; j<= w ;j++){
            if(arr[i-1] <= j )
            dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][w];
}

int CountSpaceOP(vector<int> arr,int n, int w){
    
    int prev = 
    for(int i = 1; i<= n ;i++){
        for(int j = 1; j<= w ;j++){
            if(arr[i-1] <= j )
            dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][w];
}


int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n+1,vector<int>(tar+1));
//     int res = CountMemo(num,n,tar,dp);
    int res = CountTabulor(num,n,tar,dp);
    return res;
    // Write your code here.
}