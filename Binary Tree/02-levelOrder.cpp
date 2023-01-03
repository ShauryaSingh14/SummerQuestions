#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int key ;
    Node * left;
    Node * right;
    Node(int key){
        this->key = key;
        left = NULL;
        right = NULL;
    }
};
int height(Node * root){
    if(!root)
    return 0;
    else 
    return max(height(root->left),height(root->right))+1;
}
void printKthDis(Node * root, int k){
     if(!root)
     return;
     if(k == 0)
     cout << root->key << " ";
     else{
         printKthDis(root->left,k-1);
         printKthDis(root->right,k-1);
     }
}
void levelOrder(Node * root){
    int h = height(root);
    int k = 0;  //Time : O(n + n*h)
    while(h != -1){
        printKthDis(root,k);
        k++;
        h--;
    }
}
void levelOrderII(Node * root){
    if(!root)
    return ;
    queue <Node*> q; 
    q.push(root);
    while(!q.empty()){
        Node * curr = q.front();
        q.pop();
        cout << curr->key << " ";
        
        if(!curr->left)
        q.push(curr->left);
        
        if(!curr->right)
        q.push(curr->right);
    }
}
int main() {
    Node * root = new Node(10);
    root->left = new Node(20);
    root -> right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    root->left->right->left = new Node(70);
    levelOrder(root); // O(n * h)
    levelOrderII(root); // T theta( n )

    return 0;
}