#include <iostream>

using namespace std;

class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

bool trans(BinaryTreeNode<int> *root, int minVal, int maxVal){
    
    if(!root)
        return true;
    
    if(root->data >= minVal && root->data <= maxVal){
        
    bool left = trans(root->left,minVal,root->data);
    bool right = trans(root->right,root->data,maxVal);
        
        return left && right;
    }
    else
    return false;
}
bool validateBST(BinaryTreeNode<int> *root) {
    
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    
    bool ans = trans(root,maxVal,minVal);
    
    return ans;
    
}
int main(){
    return 0;
}