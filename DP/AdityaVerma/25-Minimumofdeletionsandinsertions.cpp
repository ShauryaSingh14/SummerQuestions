//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
int tcs(int x,int y, string s1, string s2){
    
    vector<vector<int>> dp(x+1,vector<int>(y+1,-1)); 
        for(int i=0 ; i< x+1 ; i++){
            for(int j =0 ; j< y +1 ;j++){
                if(i == 0 || j == 0)
                dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i< x+1 ;i++){
            
            for(int j = 1; j< y+1;j++){
                
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
	int minOperations(string str1, string str2) 
	{ 
	  int n = str1.length();
	  int m = str2.length();
	  
	  
	  int clen = tcs(n,m,str1,str2);
	  
	  int ans = n+m - 2*clen;
	  
	  return ans ;
	  
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends