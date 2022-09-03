#include<bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    
    // creating Adj 
    unordered_map <int,list<int>> adj;
  for(int i = 0 ; i<m ;i++){
      int u = edges[i].first;
      int v = edges[i].second;
      
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
    
    vector<int> visited(n,0);
    unordered_map <int,int> parent;
    
    queue<int> q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto it : adj[front]){
            if(!visited[it]){
                visited[it] = 1;
                parent[it]=front;
                q.push(it);
            }
        }
        
    }
    vector <int> ans;
    int curr = t;
    ans.push_back(t);
    
    while(curr != s){
        curr = parent[curr];
        ans.push_back(curr);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

