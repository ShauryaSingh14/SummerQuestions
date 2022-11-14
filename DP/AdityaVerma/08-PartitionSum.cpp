#include <iostream>
#include <vector>
using namespace std;

// Try to think this problem as a smaller problem
// if we want our set divided into two equal subsets, only possible when the sum whole set
// is even
bool knapSackTopDown(vector<int> arr,int n, long long w,
                    vector<vector<bool>> & dp){
    
    for(int i =0 ; i< n+1 ;i++){
        for(int j = 0 ; j< w+1 ;j++){
            
            if(i == 0)
            dp[i][j]=false;
            
            if(j == 0)
            dp[i][j]=true;
        }
    }
    
    for(int i =1 ; i< n+1 ;i++){
        for(int j =1 ; j<w+1 ;j++){
            if(arr[i-1] <= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
        
    }
    
    return dp[n][w];
}
    bool canPartition(vector<int>& nums) {
        long long sum =0;
        int n = nums.size();

        for(auto it : nums)
        sum+=it;

        if(sum%2!=0)
        return false;

        vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1));
        return knapSackTopDown(nums,n,sum/2,dp);
        
    }

int main(){
     cout << "hepp ";
    vector<int> nums={100,100,100,100,100,100,100,100,100,100,100,100,100,100,
    100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
    100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100
    ,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
    100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
    100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
    100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
    100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
    100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
    100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
    100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};

        cout << canPartition(nums);
    return 0;
    }