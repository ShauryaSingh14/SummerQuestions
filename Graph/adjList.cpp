// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[],int V){
    for(int i =0 ; i< V ;i++){
        cout << i <<" : ";
        
        for(auto it : adj[i])
        cout << it << " ";

        cout << endl;
    }
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