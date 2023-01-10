//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
 long long int topDownApproch(int wt[],int n, int w,
    vector<vector<long long int>>&dp){
        
        //initization (Base Case)
        for(int i = 0; i<n+1;i++){
            for(int j =0 ; j<w+1;j++){
                if(i == 0 )
                dp[i][j] = 0;
                if(j == 0)
                dp[i][j] = 1;
            }
        }
        
         // Choice Diagram
        for(int i = 1; i< n+1;i++){
            for(int j = 1; j<w+1;j++){
            if(wt[i-1] <= j){
            dp[i][j] = dp[i][j-wt[i-1]] +
                             dp[i-1][j];
        }
        else{
            dp[i][j] = dp[i-1][j];
        }
            
            }
        }
    
        return dp[n][w];
        
    }
    
    long long int count(int coins[], int N, int sum) {
        
        vector<vector<long long int  >> dp(N+1,vector<long long int>(sum+1));
        return topDownApproch(coins,N,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
