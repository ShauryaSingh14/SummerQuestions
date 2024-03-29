// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	   long long maxPro = arr[0];
	   long long ma = arr[0];
	   long long mi = arr[0];
	   for( int i =1 ; i< n ;i++){
	       
	       if(arr[i] < 0)
	       swap(ma,mi);
	       
	       ma = arr[i]>arr[i]*ma?arr[i]:arr[i]*ma;
	       mi = arr[i]<arr[i]*mi?arr[i]:arr[i]*mi;
	       maxPro = max(maxPro,ma);
	   }
	   return maxPro;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends