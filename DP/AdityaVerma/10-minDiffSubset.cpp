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
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int s1 =0;
	    int s2 = 0;
	    for(auto it : arr)
	        s2+= it;
	   
	   return minDiffRec(arr,n,s1,s2);     
	   
	   
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