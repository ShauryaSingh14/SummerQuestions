#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> sums ;
   
    for(int i =0; i<arr.size();i++){
        for(int j = i+1 ; j<arr.size();j++){
            if(arr[i]+arr[j]==s)
            {
                vector<int> pair;
                pair.push_back(min(arr[i],arr[j]));
                pair.push_back(max(arr[i],arr[j]));
                sums.push_back(pair);
            }   
        }
    }
    sort(sums.begin(),sums.end());
    return sums;
}
int main(){
    return 0;
}