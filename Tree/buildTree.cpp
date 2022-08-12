// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node{
  int data;
  Node * leftNode;
  Node * rightNode;
  Node(int data){
      this->data = data;
      leftNode = rightNode = NULL;
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
    root->leftNode = buildTree(root->leftNode);
    cout << "Enter the data for right of " << data << endl;
    root->rightNode = buildTree(root->rightNode);
    
    return root;
  }

int main() {
   Node * root = NULL;
   
   root = buildTree(root);
   

    return 0;
}