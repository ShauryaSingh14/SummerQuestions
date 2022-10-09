class Solution {
public:

void KsumSubSeq(vector<int>& arr,int i,
                    vector<int> &seq, int k,
                    vector<vector<int>> &ans){
    if(i == arr.size()){
       if(k==0)
        ans.push_back(seq);
    return;
    }

    if(arr[i] <= k){
    seq.push_back(arr[i]);
    KsumSubSeq(arr,i,seq,k-arr[i],ans);
    seq.pop_back();
    }
    
    KsumSubSeq(arr,i+1,seq,k,ans); 

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res; 
    vector <int> seq;
        KsumSubSeq(candidates,0,seq,target,res);
        return res;
    }
};
