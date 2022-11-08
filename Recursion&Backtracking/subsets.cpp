// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void subSets(string s, string curr , int idx){
    if( idx == s.length())
    {
        cout << curr << " ";
        return;
    }
    subSets(s,curr,idx+1);
    subSets(s,curr + s[idx],idx+1);
}
// GFG Question
void solve(int n,vector<int> &A,vector<int>&sub, vector<vector<int>>& res){
        if(n == A.size()){
         res.push_back(sub);
        return;
        }


            sub.push_back(A[n]);
            solve(n+1,A,sub,res);
            sub.pop_back();
            solve(n+1,A,sub,res);

    }
    vector<vector<int> > subsetsII(vector<int>& A)
    {
        vector<vector<int>> res;
        vector<int> sub;
        solve(0,A,sub,res);
        sort(res.begin(),res.end());
        return res;
        
    } 
    
int main() {
    
    string s = "ABC";
    subSets(s,"",0);
    cout << endl;
    return 0;
}