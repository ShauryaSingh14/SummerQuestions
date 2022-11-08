//{ Driver Code Starts
//Initial template for C++

#include <iostream>
#include <vector>
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool knapSackRec(vector<int> arr,int n,int w){
    if( n == 0){
        if(w == 0)
        return true;
        
        return false;
    }
    
    if(arr[n-1] <= w ){
    return knapSackRec(arr,n-1,w-arr[n-1]) || knapSackRec(arr,n-1,w);
    }
    else{
    return knapSackRec(arr,n-1,w);
    }
}

// bool knapSackMemo(vector<int> arr,int n,int w,
//                  vector<vector<int>> &ans){
//     if( n == 0){
//         if(w == 0)
//         return 1;

//         return 0;
//     }
//     if(ans[n-1][w] != -1)
//     return ans[n][w];
    
//     if(arr[n-1] <= w ){
//     return ans[n][w] = knapSackMemo(arr,n-1,w-arr[n-1],ans) || knapSackMemo(arr,n-1,w,ans);
//     }
//     else{
//     return ans[n][w] = knapSackMemo(arr,n-1,w,ans);
//     }
    
// }
// int knapSackTopDown(vector<int> arr,int n, int w,
//                     vector<vector<int>> & dp){
    
//     for(int i =0 ; i< n ;i++){
//         for(int j = 0 ; j< w ;i++){
//             dp[i][j]=
            
//         }
//     }
    
// }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
       bool res = false;
       int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return knapSackRec(arr,arr.size(),sum);
        
       
       
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