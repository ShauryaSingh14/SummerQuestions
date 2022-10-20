//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m,int n,int x,int y,
               vector<string> &ans,string &str,
               vector<vector<bool>> &vis){
       
        if(x == n-1 && y == n-1 && m[x][y]){
            
            ans.push_back(str);
            return;
        }
        
        if( x >= 0 && x < n &&  y >=0 && y < n
                && !vis[x][y] && m[x][y] ){
        for(int i = 0 ; i<4 ;i++){
            if( i == 0){
                str.push_back('R');
                vis[x][y]=1;
                solve(m,n,x,y+1,ans,str,vis);
                vis[x][y]=0;
                str.pop_back();   
                }
            
            if (i == 1){
                str.push_back('U');
                vis[x][y]=1;
                solve(m,n,x-1,y,ans,str,vis);
                vis[x][y]=0;
                str.pop_back();   
                
            }
            if(i == 2 ){
                str.push_back('D');
                vis[x][y]=1;
                solve(m,n,x+1,y,ans,str,vis);
                vis[x][y]=0;
                str.pop_back();   
                
            }
            if(i == 3){
                str.push_back('L');
                vis[x][y]=1;
                solve(m,n,x,y-1,ans,str,vis);
                vis[x][y]=0;
                str.pop_back();   
                
            }
        }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>> vis(n,vector<bool> (n, 0));
        vector<string> res;
        string s="";
        int x = 0,y =0;
        solve(m,n,x,y,res,s,vis);
        return res;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends