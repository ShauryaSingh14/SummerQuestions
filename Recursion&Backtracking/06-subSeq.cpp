// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
// Subsequence :- a continuous/ non continuous sequence that follow certain order.
// Example, [1,2,3] 
// continuous '1','2','3','1,2','2,1','1,2,3'
// non-continuous - '1','2','3','1,2','2,1','1,3','1,2,3'

void subSeq(vector<int> arr,int i, vector<int> seq ){
    if(i >= arr.size()){
        cout << "{ ";
        for(auto it : seq)
        cout << it <<", ";
        
        cout << " }" << endl;
        return;
    }
    
    subSeq(arr,i+1,seq);
    seq.push_back(arr[i]);
    
    subSeq(arr,i+1,seq);
    seq.pop_back();
    // seq.erase(seq.end()-1);
    0
}
// print all the subsequene with K Sum
void KsumSeq(int n, vector<int> arr,vector<int> seq,int sum,int target){
    if(n == arr.size()){
        if(sum == target){
            for(auto it : seq){
                cout << it <<" ";
            }
            cout<< endl;
        }
        return;
    }
    // Pick Case
    seq.push_back(arr[n]);
    sum+=arr[n];
    KsumSeq(n+1,arr,seq,sum,target);
    sum-=arr[n];
    seq.pop_back();

    // Not Picked Case
    KsumSeq(n+1,arr,seq,sum,target);
}

// Print Only one Subsequence with K sum
bool KsumOneSeq(int n, vector<int> arr,vector<int> seq,int sum,int target){
    if(n == arr.size()){
        if(sum == target){
            for(auto it : seq){
                cout << it <<" ";
            }
            cout<< endl;
            return true;
        }
        return false;
    }
    // Pick Case
    seq.push_back(arr[n]);
    sum+=arr[n];
    bool pickCase = KsumOneSeq(n+1,arr,seq,sum,target);
    sum-=arr[n];
    seq.pop_back();

    // Not Picked Case
    bool notPickCase = KsumOneSeq(n+1,arr,seq,sum,target);

    return pickCase && notPickCase;
}

// Print no. of SubSequence Possible 
int KsumNSeq(int n, vector<int> arr,vector<int> seq,int sum,int target){
    if(n == arr.size()){
        if(sum == target){
            return 1;
        }
        return 0;
    }
    // Pick Case
    seq.push_back(arr[n]);
    sum+=arr[n];
    int pickCase = KsumOneSeq(n+1,arr,seq,sum,target);
    sum-=arr[n];
    seq.pop_back();

    // Not Picked Case
    int notPickCase = KsumOneSeq(n+1,arr,seq,sum,target);

    return pickCase + notPickCase;
}
int main() {
    vector<int> arr={1,2,1};
    vector<int> seq;
    subSeq(arr,0,seq);
    KsumSeq(0,arr,seq,0,2);
    bool store = KsumOneSeq(0,arr,seq,0,2);
    cout << "No. of Subseq "<< KsumNSeq(0,arr,seq,0,2);
    
    return 0;
}