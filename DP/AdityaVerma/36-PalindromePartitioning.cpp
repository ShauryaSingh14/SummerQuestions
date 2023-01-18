//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false;  
      i++;
      j--;
    }
    return true;
}
int recuriveApproch(string s, int i ,int j){
     if(i >= j || isPalindrome(s,i,j))
     return 0;

     int ans = INT_MAX;
     for(int k = i ; k < j ;k++){
        int tempAns = recuriveApproch(s,i,k,dp) + 
                      recuriveApproch(s,k+1,j,dp) + 1;
        
        ans = min(tempAns,ans);
     }
     return ans;
 }
int memoApproch(string s, int i ,int j,
                vector<vector<int>> &dp){
     if(i >= j || isPalindrome(s,i,j))
     return 0;
     
     if(dp[i][j] != -1)
     return dp[i][j];
     
     int ans = INT_MAX;
     for(int k = i ; k < j ;k++){
        int tempAns = memoApproch(s,i,k,dp) + 
                      memoApproch(s,k+1,j,dp) + 1;
        
        ans = min(tempAns,ans);
     }
     return dp[i][j] = ans;
 }
 int memoApprochOpt(string s, int i ,int j,
                vector<vector<int>> &dp){
     if(i >= j || isPalindrome(s,i,j))
     return 0;
     
     if(dp[i][j] != -1)
     return dp[i][j];
     
     int ans = INT_MAX;
     for(int k = i ; k < j ;k++){
         
        int left,right ;
        
        if(dp[i][k] != -1)
        left = dp[i][k];
        else
        left = memoApprochOpt(s,i,k,dp);
        
        if(dp[k+1][j] != -1)
        right = dp[k+1][j];
        else
        right = memoApprochOpt(s,k+1,j,dp);
        
        int tempAns = left + right + 1;
        
        ans = min(tempAns,ans);
     }
     return dp[i][j] = ans;
 }
    int palindromicPartition(string str)
    {
        int i =0 , j = str.length();
        vector<vector<int>> dp(j+1,vector<int>(j+1,-1));
        return recuriveApproch(str ,i,j-1);
        return memoApproch(str ,i,j-1,dp);
        return memoApprochOpt(str ,i,j-1,dp);
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends