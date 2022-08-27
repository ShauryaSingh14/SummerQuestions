#include <iostream>
using namespace std;

    template <typename T>
    class BinaryTreeNode {
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

int countLeaf(BinaryTreeNode<int> *root, int count){
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
  
         count+= countLeaf(root->left,count) + countLeaf(root->right,count);
        return count;   
    
}

// love Bubbar Menthod 
void inorderCount(BinaryTreeNode<int> *root , int & count){
    if(!root)
        return;
     inorderCount(root->left,count);
    if(!root->left && !root->right)
        count++;
    inorderCount(root->right,count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count =0;
//     count = countLeaf(root,count); my method
    inorderCount(root,count);
    
    return count;
}
int main(){
    return 0;
}