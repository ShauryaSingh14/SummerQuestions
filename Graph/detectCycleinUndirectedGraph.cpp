//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(int node,vector<int>adj[], vector<bool> &vis){
        unordered_map<int,int> parent;
        parent[node] =-1;
        vis[node] = 1;
        
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto it : adj[front]){
                if(vis[it] && it != parent[front])
                return true;
                else if(!vis[it]){
                    q.push(it);
                    vis[it] = true;
                    parent[it] = front;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
    vector<bool> vis(V,false);
    for(int i =0 ; i<V;i++){
        if(!vis[i]){
        if( check(i,adj,vis) )
             return true;
        }
    }
    return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends