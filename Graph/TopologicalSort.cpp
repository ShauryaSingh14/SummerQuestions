//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
// using dfs ::

	void solveUsingDfs(int node,vector<int> adj[],vector<bool>&vis,stack<int>&ans){
	   
	    vis[node]= true;
	    
	    for(auto it : adj[node]){
	        if(!vis[it])
	            solveUsingDfs(it,adj,vis,ans);
	    }

	    ans.push(node); // push into stack when there

	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector <bool> vis(V,0);
	    stack <int> ans;
	    vector <int> res;
	    for(int i =0 ; i<V ;i++){
	        
	        if(!vis[i])
	          solveUsingDfs(i,adj,vis,ans);
	          
	    }
	    while(!ans.empty()){
	        res.push_back(ans.top());
	        ans.pop();
	    }
	    
	    return res;
	    
	}

    // using Bfs( Khan's Algo)
    vector <int> topoSortBfs(int V, vector<int> adj[]){
        unordered_map <int,int> indegree;
        vector <int> ans;
        // Store the indegree of Node in the graph
        for(auto it : adj){
            for(auto j : adj.second){
                indegree[i]++;
            }
        }

        queue<int> q;
        // push node with zero degree in the queue
        for(int i =0 ; i<V ; i++ ){
            if(indegree[i]==0)
            q.push(i);
        }

        // do bfs
        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push(front);
            for(auto it : adj[front]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);

            }

        }

        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends