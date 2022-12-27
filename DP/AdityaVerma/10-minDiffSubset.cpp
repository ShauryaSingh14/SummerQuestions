//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  int minDiffRec(int arr[],int n,int s1,int s2){
      if(n == 0){
          return abs(s1- s2);
      }
      return min(minDiffRec(arr,n-1,s1,s2),
      minDiffRec(arr,n-1,s1+arr[n-1],s2-arr[n-1]));
     
  }
  
  
  int minDiffMemo(int arr[],int n,int s1,int s2,
        vector<vector<int>> &dp){
     if(n == 0){
          return abs(s1- s2);
      }
      
      if(dp[n][s1] != -1 )
      return dp[n][s1];
      
      return dp[n][s1] = min(minDiffRec(arr,n-1,s1,s2),
      minDiffRec(arr,n-1,s1+arr[n-1],s2-arr[n-1]));
  }
  
  
  int minDiffTabulor(int arr[],int n,int s1,int s2,
        vector<vector<int>> &dp){
    
    for(int i =0 ; i<= n ;i++){
        for(int j =0 ; j<= s2 ;j++){
            if(i == 0)
            dp[i][j] = abs(s1 - s2);
        }
    }
    
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=s2 ;j++){
            dp[i][j] = min(dp[i-1][s1+arr[i-1]],dp[i-1][s1]);
        }
    }
    return dp[n][s1];
    
        }
        
        
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int s1 =0;
	    int s2 = 0;

	   for(int i =0 ; i< n ;i++){
	       s2 += arr[i];
	   }
	   
	   vector<vector<int>> dp(n+1,vector<int>(s2+1,0));
	   //return minDiffRec(arr,n,s1,s2);   
	   //return minDiffMemo(arr,n,s1,s2,dp);  
	   return minDiffTabulor(arr,n,s1,s2,dp);
	   
	   
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends