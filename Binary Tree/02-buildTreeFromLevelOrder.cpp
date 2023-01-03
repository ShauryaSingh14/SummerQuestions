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
void buildTreefromLevelOrder(Node *& root){
    int data;
    cout << "Enter the data: ";
    cin >> data;

    root = new Node(data);
    queue <Node *> q;
    q.push(root);
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        cin >> data;
        if(data != -1){
         temp->left = new Node(data);   
         q.push(temp->left);
        }
        
        cin>> data;
        if(data!= -1){
            temp->right = new Node(data);
             q.push(temp->right);
        }
    
    }
    
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
    
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
   Node * root = NULL;
   
   buildTreefromLevelOrder(root);
   cout << endl;
   
   levelOrderTrans(root);
   cout << endl;

    return 0;
}

