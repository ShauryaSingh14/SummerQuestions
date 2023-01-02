//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
// bool knapSackRec(vector<int> arr,int n,int w){
//     if( n == 0){
//         if(w == 0)
//         return true;
        
//         return false;
//     }
    
//     if(arr[n-1] <= w ){
//     return knapSackRec(arr,n-1,w-arr[n-1]) || knapSackRec(arr,n-1,w);
//     }
//     else{
//     return knapSackRec(arr,n-1,w);
//     }
// }

// bool knapSackMemo(vector<int> arr,int n,int w,
//                  vector<vector<bool>> &ans){
//     if( n == 0){
//         if(w == 0)
//         return true;

//         return false;
//     }

//     if(ans[n-1][w] != 0)
//     return ans[n][w];
    
//     if(arr[n-1] <= w ){
//     ans[n][w] = knapSackMemo(arr,n-1,w-arr[n-1],ans) || knapSackMemo(arr,n-1,w,ans);
//     }
//     else{
//     ans[n][w] = knapSackMemo(arr,n-1,w,ans);
//     }
    
//     return ans[n][w];
// }


bool knapSackTopDown(vector<int> arr,int n, int w,
                    vector<vector<bool>> & dp){
    
    for(int i =0 ; i< n+1 ;i++){
        for(int j = 0 ; j< w+1 ;j++){
            
            if(i == 0)
            dp[i][j]=false;
            
            if(j == 0)
            dp[i][j]=true;
        }
    }
    
    for(int i =1 ; i<n+1 ;i++){
        for(int j =1 ; j<w+1 ;j++){
            if(arr[i-1] <= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
        
    }
    
    return dp[n][w];
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
       bool res = false;
       int n = arr.size();
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1));

    return knapSackTopDown(arr,arr.size(),sum,dp);
        
       
       
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends