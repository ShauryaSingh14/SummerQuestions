// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
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
    
}
int main() {
    vector<int> arr={1,2,3};
    vector<int> seq;
    subSeq(arr,0,seq);

    return 0;
}