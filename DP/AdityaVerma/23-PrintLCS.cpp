// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string printLCS(int n, int m, string s1, string s2){
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i =0 ; i< n+1; i++){
        for(int j =0 ; j< m+1 ;j++){
            if(i == 0 || j == 0)
            dp[i][j] = 0;
        }
    }
    
    for(int i = 1; i< n+1; i++){
        for(int j =1 ;j< m+1 ;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] +1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    string s="";
    int i = n, j =m;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            s.push_back(s1[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
    }
    
}
    reverse(s.begin(),s.end());
     return s;
}
int main() {
    
    string s1 ="ABCD";
    string s2 ="ABECD";
    
    int n = s1.length();
    int m = s2.length();
    
    cout << printLCS(n,m,s1,s2);
    return 0;
}