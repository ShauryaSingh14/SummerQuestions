#include <iostream>
#include <vector>
using namespace std;
vector <int> dijkshraAlgo(vector<int> adj[], vector<int> &vis, int node,int V){
    vector <int> sd(V,INT_MAX);
    vector <bool> fin(V,0);
    sd[node]= 0;
    for(int count =0 ; count<V-1;count++){
        int u = -1;
        for(int i =0 ; i<V ;i++){
            if(!fin[i] && ( u == -1 || (sd[i] < sd[u]) ))
                u = i;
        }

        fin[u]=true;

        for(int v =0 ; v<V;v++){
            if(sd[v]!= 0 && !fin[v])
            sd[v]= min(sd[v],sd[u]+1);
        }
    }
    return sd;
}
int main(){

    return 0;
}