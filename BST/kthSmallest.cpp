/*************************************************************
 
    Following is the Binary Tree node structure
    
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

*************************************************************/
void inorder(BinaryTreeNode<int>* root, int& res, int &k){
    if(!root)
    return;
    
    inorder(root->left,res,k);
    
    k--;
    if(k==0)
        res = root->data;
     
    inorder(root->right,res,k);
    
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int kth=-1;
    inorder(root,kth,k);
    return kth;
}