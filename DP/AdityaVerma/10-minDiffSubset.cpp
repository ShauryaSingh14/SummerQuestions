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
        
 // Aditya Verma Approch
  int tabulorApproch( int arr[], int n,int sum){
      vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
      // making table of subsetSum 
      for(int i =0 ; i< n+1 ;i++){
          for(int j =0 ; j< sum+1 ; j++){
              if(i == 0 )
            dp[i][j] = false;
            if(j == 0)
            dp[i][j] = true;
          }
      }
      
      for(int i = 1; i< n+1 ;i++){
          for(int j = 0 ; j< sum+1;j++){
              
            if(arr[i-1] <= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
          }
      }
      
      vector<int> v;
      // Extacting the last row of it coz it's impt 
      for(int i = 0 ; i<= sum/2 ; i++){
          if(dp[n][i] == 1) 
            v.push_back(i);
      }
      
      int minDiff = INT_MAX;
      // we known to find the difference of two subsets 
      // (Range - 2*S1)
      // and we want min of all of them then,
      // min(Range - 2 * S1)
      for(int i =0 ; i< v.size();i++){
          minDiff = min(minDiff, sum - 2*v[i]);
      }
      
      return minDiff;
  }
	int minDifference(int arr[], int n)  { 
	    int sum =0 ;
	    for(int i =0 ; i< n;i++){
	        sum+=arr[i];
	    }
	    
	    return tabulorApproch(arr,n,sum);
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