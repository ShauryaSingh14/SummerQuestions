#include <iostream>
#include <set>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
int doUnion(int arr1[], int n1, int arr2[], int n2){
sort(arr1,arr1+n1);
sort(arr2,arr2+n2);
    int ptr1 =0;
    int ptr2 =0;
    set <int> arr; 
    while(ptr1<n1 && ptr2<n2){
        if(arr1[ptr1]<arr2[ptr2]){
            arr.insert(arr1[ptr1]);
            ptr1++;
        }
        else if(arr1[ptr1]==arr2[ptr2]){
            arr.insert(arr1[ptr1]);
            ptr1++;
            ptr2++;
        }
        else {
             arr.insert(arr2[ptr2]);
            ptr2++;
        }
    }
    while(ptr1 < n1){
        arr.insert(arr1[ptr1]);
            ptr1++;
        
    }
    while(ptr2 < n2){
        
        arr.insert(arr2[ptr2]);
            ptr2++;
    }
    return arr.size();
}
};

// 
// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends