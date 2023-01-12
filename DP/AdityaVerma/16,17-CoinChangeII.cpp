//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int CountTabulor(int coins[],int n, int w, vector<vector<int>> &dp){
    
    for(int i =0 ; i<= n; i++){
        for(int j =0 ; j<=w ;j++){
            
            if(j== 0)
            dp[i][j] = 0;
            
            if(i == 0)
            dp[i][j] = INT_MAX-1;

            if(i == 1){
                if(j % coins[0] == 0)
                dp[i][j] = j/coins[0];
                else 
                 dp[i][j] = INT_MAX-1;
                
            }
        }       
    }
    
    for(int i = 2; i<= n ;i++){
        for(int j = 1; j<= w ;j++){
            if(coins[i-1] <= j )
            dp[i][j] = min(dp[i][j-coins[i-1]] +1 ,dp[i-1][j]);
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    
    // Acc to Question on GFG if there is no possible way we have to return -1;
    // and our code return INT_MAX-1 when there no possible way , to handly this we 
    // apply this condition 
    
    if(dp[n][w] == INT_MAX-1)
    return -1;
    
    return dp[n][w];
}

    
	int minCoins(int coins[], int M, int V) 
	{ 
	     vector<vector<int>> dp(M+1,vector<int>(V+1));
	     return CountTabulor(coins,M,V,dp);
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends