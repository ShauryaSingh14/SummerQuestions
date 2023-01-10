#include <bits/stdc++.h> 
#define a 10000000007
int countSubsetSum(vector<int> arr,int n, int w, vector<vector<int>> &dp){
    
    for(int i =0 ; i<= n; i++){
        for(int j =0 ; j<= w ;j++){
            if(i==0)
            dp[i][j] =0;
            if(j==0)
            dp[i][j] = 1;
        }       
    }
    
    for(int i = 1; i<= n ;i++){
        for(int j = 0; j<= w ;j++){
            if(arr[i-1] <= j )
            dp[i][j] = (dp[i-1][j-arr[i-1]]%a + dp[i-1][j]%a) % (a) ;
            else
            dp[i][j] = dp[i-1][j] % (a) ;
        }
    }

    return dp[n][w]  % (a)  ;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
   int sumArr = 0;
    for(auto it : arr)
        sumArr+=it;
    
    int sum1 = (d + sumArr)/2;
   if((d+sumArr)%2!=0) return 0;
    vector<vector<int>> dp(n+1,vector<int>(sum1+1));
    return countSubsetSum(arr,n,sum1,dp);
    
}


