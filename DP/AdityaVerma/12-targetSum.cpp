int countSubsetSum(vector<int>& arr,int n, int w, vector<vector<int>> &dp){
    
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
            dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j]  ;
        }
    }

    return dp[n][w] ;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sumArr = 0;
        
    for(auto it : nums)
        sumArr+=it;
    
    int sum1 = (target + sumArr)/2; 
// we take abs of target to be in range 
   if( sumArr< abs(target) || (target +sumArr)%2!=0) return 0;
    vector<vector<int>> dp(n+1,vector<int>(sum1+1));
    return countSubsetSum(nums,n,sum1,dp); 
    }