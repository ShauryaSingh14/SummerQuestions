class Solution {
public:
void solve(vector<int>&arr, vector<int>&seq,
            vector<vector<int>>& ans, int flag[]){

    if(seq.size()==arr.size()){
         ans.push_back(seq);
         return;
    }

    for(int i =0 ;i<arr.size();i++){
        if(!flag[i]){
            seq.push_back(arr[i]);
            flag[i] = 1;
            solve(arr,seq,ans,flag);

            flag[i]=0;
            seq.pop_back();
        }
    }

}
    vector<vector<int>> permute(vector<int>& nums) {
        
        int flag[nums.size()];
        for(int i =0; i< nums.size();i++){
            flag[i]=0;
        }
        vector<int> seq;
        vector<vector<int>> ans;
        solve(nums,seq,ans,flag);
        return ans;
    }
};

/// second approch

class Solution {
public:
void solve(vector<int> &arr,
            vector<vector<int>>& ans, int idx){
    if(arr.size()==idx){
                    ans.push_back(arr);
                    return;
                }
    for(int i = idx ;i<arr.size();i++){
            swap(arr[idx],arr[i]);
            solve(arr,ans,idx+1);
             swap(arr[idx],arr[i]);
    }

}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int idx =0;
        solve(nums,ans,idx);
        return ans;
    }
};