#include <iostream>
using namespace std;
class BinaryTreeNode {
    public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
bool searchInBST(BinaryTreeNode *root, int x) {
    // Write your code here.
    if(!root)
        return false;
    bool ans;
    if(root->data==x)
        return true;
    else if(root->data>x)
        ans = searchInBST(root->left,x);
    else
        ans = searchInBST(root->right,x);
    
    return ans;
}
