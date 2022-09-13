// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Directed Graph 
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}

//Print
void printGraph(vector<int> adj[],int V){
    for(int i =0 ; i< V ;i++){
        cout << i <<" : ";
        
        for(auto it : adj[i])
        cout << it << " ";

        cout << endl;
    }
}

void dfsRec(int node,vector<int> adj[],vector<int> visited,
            stack<int> st){
    visited[node]=true;
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            dfsRec(nbr,adj,visited,st);
        }
    }
    st.push(node);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<int> adj[];
	for(int i =0 ; i<edges.size();i++){
        int u =edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    stack<int> st;
    vector<bool> visited(edges.size(),false);
    
    for(int i =0 ;i<v;i++){
        if(!visited[i]){
            dfsRec(i,adj,visited,st);
        }
    }
    
    vector <int> transpose[];
    for(int i =0 ; i< v;i++){
        for(auto nbr : i){
            transpose[nbr].push_back(i);
        }
    }
    
    vector<bool> visited(edges.size(),false);
    int count =0;
    while(!st.empty()){
        int top = st.top();
        st.top();
        st.pop();
        if(!visited[top]){
            count++;
            resDfs(top,vis,transpose);
        }
    }
    return count;
    }
    
int main() {
    int vex;
    cout << "Enter No. of Vextex ";
    cin >> vex;
    vector<int> adj[vex];
    addEdge(adj,1,0);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,0);
    addEdge(adj,2,3);
    
    printGraph(adj,4);

    return 0;
}