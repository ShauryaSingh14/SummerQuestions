//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    

    int longestCommonSubstr (string s1, string s2, int x, int y)
    {
         vector<vector<int>> dp(x+1,vector<int>(y+1,-1)); 
         
        for(int i=0 ; i< x+1 ; i++){
            for(int j =0 ; j< y +1 ;j++){
                if(i == 0 || j == 0)
                dp[i][j] = 0;
            }
        }
        
        int maxLen = 0 ;
        for(int i = 1; i< x+1 ;i++){
            
            for(int j = 1; j< y+1;j++){
                
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                    maxLen = max(maxLen,dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
    
        return maxLen;
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// } Driver Code Ends