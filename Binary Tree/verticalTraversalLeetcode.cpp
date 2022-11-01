/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map< int, map<int,vector<int> >>nodes;
        queue< pair< TreeNode*, pair<int,int> > > q;
        q.push(make_pair(root,make_pair(0,0)));

        vector<vector<int>> ans;
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();

            TreeNode * front = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            nodes[hd][lvl].push_back(front->val);

            if(front->left)
                q.push(make_pair(front->left,make_pair(hd-1,lvl+1)));
            
            if(front->right)
                q.push(make_pair(front->right,make_pair(hd+1,lvl+1)));
            
        }
        for(auto i : nodes){ // iterate over different values
          vector<int> temp;
        for(auto j : i.second){// here those values came whose hd are same 
            vector<int> temp2;
            for(auto k : j.second){ // values came whose lvl and hd, both are same.
               temp2.push_back(k);
            }
            sort(temp2.begin(),temp2.end());
            for(auto l: temp2) temp.push_back(l);
        }
         ans.push_back(temp);
         
        }
   
        return ans;
    }
};