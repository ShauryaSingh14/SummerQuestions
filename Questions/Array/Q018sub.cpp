// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

pair<int,int> subArrSum(vector <int> &arr,int sum){
    int currSum = 0;
    pair <int,int> pr;
    pr.first = 0;
    pr.second = -1;
    unordered_map<int,int> m;
    for(int i =0 ; i< arr.size();i++){
        currSum += arr[i];
        if(currSum == sum){
        pr.second = i;
        return pr;
        }
        else if(m.find(currSum - sum) != m.end() ){
            pr.first = m[currSum-sum]+1;
            pr.second = i;   
            return pr;
        }
        else{
            m[currSum]=i;
        }
    }
    return pr;
}
int cNumsubArrSum(vector <int> &arr,int sum){
   int currSum = 0;
   int count=0;
    unordered_map<int,int> m;
    for(int i =0 ; i< arr.size();i++){
        currSum += arr[i];
        if(currSum == sum){
            count++;
        }
        else if(m.find(currSum - sum) != m.end() ){
            count++;
        }
        else{
            m[currSum]=i;
        }
    }
    return count;
}
int main() {
    vector <int> arr ={7,1,5,3,6,4};
    pair<int,int> pr = subArrSum(arr,9); // return idx of first subarray with given sum
    cout << pr.first<<" ";
    cout <<pr.second <<" ";
    cout << cNumsubArrSum(arr,9); // Count total number of subarray with given sum
    return 0;
    }