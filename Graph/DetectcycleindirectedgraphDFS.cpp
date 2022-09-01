//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkdfs(int node,vector<int>adj[],vector<bool>&vis,
    vector<bool>&visDfs){
        
        vis[node] = true;
        visDfs[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]){
                
                bool val = checkdfs(it,adj,vis,visDfs);
                
                if(val)
                return true;
            }
            else if(visDfs[it])
                return true;
        }
        visDfs[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,0);
        vector<bool> visDfs(V,0);
        
        for(int i =0 ; i< V;i++){
            if(!vis[i]){
                if(checkdfs(i,adj,vis,visDfs)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends