

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

BinaryTreeNode<int>* Predecessor(BinaryTreeNode<int>*root){
    if(!root)
        return;
    if(!root->right)
        return root;
    Predecessor(root->right);
}
BinaryTreeNode<int>* Successor(BinaryTreeNode<int>* root){
    if(!root)
        return ;
    if(!root->left)
        return root;
    Successor(root->left);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> ps;
    if(!root)
        return ps;
    
    ps.first = Predecessor(root->right);
    ps.second = Successor(root->left);
    
    return ps;
}

