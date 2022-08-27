// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node{
  int data;
  Node * left;
  Node * right;
  Node(int data){
      this->data = data;
      left = right = NULL;
  }
};
Node *  buildTree(Node * root){
    
    int data;
    cout << "Enter the node data : ";
    cin >> data;
    root = new Node(data);
    
    if(data==-1)
    return NULL;
    
    cout << "Enter the data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right of " << data << endl;
    root->right = buildTree(root->right);
    
    return root;
  }
void inOrder(Node * root){
    if(!root)
    return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    
}
void preOrder(Node * root){
   if(!root)
    return;
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right); 
}
void postOrder(Node * root){
   if(!root)
    return;
    
    postOrder(root->left);
    postOrder(root->right); 
    cout << root->data << " ";
}

int main() {
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
   Node * root = NULL;
   
   root = buildTree(root);
   cout << endl;

   inOrder(root);
   cout << endl;
   
   preOrder(root);
   cout << endl;
   
   postOrder(root);
   cout << endl;

    return 0;
}