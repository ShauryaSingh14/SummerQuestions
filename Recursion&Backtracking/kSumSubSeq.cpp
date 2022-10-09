// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
// To Print All the Subseq with k sum 
void KsumSubSeq(vector<int> arr,int i, vector<int> seq, int sum ,int k ){
    if(i == arr.size() ){
       if(sum == k){
        cout << "{ "; 
        for(auto it : seq)
        cout << it <<", ";
        
        cout << " }" << endl;
        }
        return;
    }

    
    seq.push_back(arr[i]);
    sum +=arr[i];
    KsumSubSeq(arr,i+1,seq,sum,k );
    
    sum -=arr[i];
    seq.pop_back();
    KsumSubSeq(arr,i+1,seq,sum,k);   
    // seq.erase(seq.end()-1);
    
}
// To print any one subSeq with K sum 
bool subSeq(vector<int> arr,int i, vector<int> seq, int sum ,int k ){
    if(i == arr.size() ){
       if(sum == k){
        cout << "{ "; 
        for(auto it : seq)
        cout << it <<", ";
        
        cout << " }" << endl;
        return true;
        }
        return false;
    }

    
    seq.push_back(arr[i]);
    sum +=arr[i];
    if(subSeq(arr,i+1,seq,sum,k))
    return true;
    
    sum -=arr[i];
    seq.pop_back();
    if(subSeq(arr,i+1,seq,sum,k))
    return true;   
    // seq.erase(seq.end()-1);
    
    return false;
    
}
// To print Count of SubSeq
void CountSubSeq(vector<int> arr,int i, vector<int> seq, 
            int sum ,int k, int &count ){
    if(i == arr.size() ){
       if(sum == k){
        count++;
        }
     return ;
    }

    
    seq.push_back(arr[i]);
    sum +=arr[i];
    CountSubSeq(arr,i+1,seq,sum,k,count);
    
    sum -=arr[i];
    seq.pop_back();
    CountSubSeq(arr,i+1,seq,sum,k,count)   ;
    // seq.erase(seq.end()-1); 
}

// Another Way to Count No. of SubSeq
int CountSubSeq(vector<int> arr,int i, vector<int> seq, 
            int sum ,int k ){
    if(i == arr.size() ){
       if(sum == k){
        return 1;
        }
     return 0 ;
    }

    
    seq.push_back(arr[i]);
    sum +=arr[i];
    int left = CountSubSeq(arr,i+1,seq,sum,k);
    
    sum -=arr[i];
    seq.pop_back();
    int right = CountSubSeq(arr,i+1,seq,sum,k);
    // seq.erase(seq.end()-1); 
    
    return left + right;
}

int main() {
    vector<int> arr={1,2,1};
    vector<int> seq;
    KsumSubSeq(arr,0,seq,0,2);

    return 0;
}