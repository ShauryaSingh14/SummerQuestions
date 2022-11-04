//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    void TowerOfHanoi(int n,int A,int B, int C,long long &count){
        if(n > 0){
            count++;
            TowerOfHanoi(n-1,A,C,B,count);
            cout <<"move disk "<< n <<" from rod "<< A << " to rod " << C <<endl;
            TowerOfHanoi(n-1,B,A,C,count);
        }
        
    }
    long long toh(int N, int from, int to, int aux) {
        long long ans = 0 ;
        TowerOfHanoi(N,from,aux,to,ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends