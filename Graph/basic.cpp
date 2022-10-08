// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <unordered_map>
#include <list>
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


int main() {
    // Write C++ code here
    Graph <int> g;
    int n ;
    cout << "Enter the number of nodes" << endl;
    cin >> n;
    
    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m ;
    
    for(int i =0 ; i<m ;i++){
        int u, v;
        cin >> u >> v;
        // creating Undirected Graph
        g.addEdge(u,v,0);
    }

    g.printAdjList();
    return 0;
}