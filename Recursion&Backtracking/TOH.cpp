#include <iostream>
#include <vector>
using namespace std;
// here A, B & C represent the the three towers
void TOH(vector<vector<int>>& arr,int n, int A, int B, int C){
    if(n>0){
        TOH(arr,n-1,A,C,B);
        vector <int> b ;
        b.push_back(A);
        b.push_back(C);
        arr.push_back(b);
        TOH(arr,n-1,B,A,C);
    }
}
vector<vector<int>> towerOfHanoi(int n)
{
    vector <vector< int>> result;
    TOH(result,n,1, 2, 3);
    return result; 
}
int main(){
    
}
