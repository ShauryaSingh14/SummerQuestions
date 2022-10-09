class Solution {
public:
void dfs(int node, vector<int> adj[], 
         vector<int> &vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }

}

int makeConnected(int n, vector<vector<int>>& connections) {
       
        vector<int> vis(n,0);
        vector<int> adj[n];
        int e =0;
        for(int i =0 ; i<connections.size() ;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            e++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        for(int i=0 ; i< n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        if(e >= n-1)
        return count-1 ;

        return -1;
    }
};