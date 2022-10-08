// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
template <typename T>


class Graph{
  public :
  unordered_map<T,list<T>> adj;
  void addEdge(T u, T v, bool directed){
    adj[u].push_back(v);
    
    if(!directed)
    adj[v].push_back(u);
}

  void printAdjList(){
    for(auto i : adj ){
        cout << i.first <<" -> ";
        for(auto j : i.second){
            cout <<j << " - ";
        }
        cout << endl;
    }
    
}
};

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
   vector<int> ans[n];
    for(int i =0; i<m;i++){
        
        int u = edges[i][0];
        int v = edges[i][1];
        
        ans[u].push_back(v);
        ans[v].push_back(u);
        //cout<<u<<"->"<<v<<endl;    
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
            
        }
    }
    vector <vector<int>> adj(n);
    for (int i =0 ; i<n ;i++){
        adj[i].push_back(i);
        for(int j =0 ; j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}
int main() {
    // Write C++ code here
    Graph <int> g;
    int m;
    cin>> m;
    vector<vector<int>> edges(m);
    for(int i = 0 ; i<m ;i++){
        for(int j =0 ; j<2 ;j++){
            int x;
            cin >> x;
            edges[i].push_back(x);
        }
    }
    printAdjacency()
    return 0;
}