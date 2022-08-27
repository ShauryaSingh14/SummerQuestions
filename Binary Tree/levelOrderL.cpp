// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
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
void levelOrderTrans(Node * root){
    cout << "Level Order Tranversal Of given tree :: " << endl;
    queue <Node *> q;
    q.push(root);
    q.push(NULL);
    while( !q.empty()){
        
        Node * temp = q.front();
        q.pop();
        
        if(!temp){
         cout << endl;
         if(!q.empty())
         q.push(NULL);
         
        }
        else{
        cout << temp->data << " ";
        
        if(temp->left)
        q.push(temp->left);
        
        if(temp->right)
        q.push(temp->right);    
        
        }
    }
}
int main() {
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
   Node * root = NULL;
   
   root = buildTree(root);
   cout << endl;
   levelOrderTrans(root);
   

    return 0;
}