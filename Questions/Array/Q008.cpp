#include <iostream>
using namespace std;
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
    long long int sum = 0;
    long long int maxSum = arr[0];
    for(int i =0 ; i< n ;i++){
        
        if(sum < 0)
        sum = 0;
        
        sum += arr[i];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends