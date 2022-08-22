#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node * minVal(Node * root){
    if(!root)
    return NULL;

    if(!root->left)
    return root;

    minVal(root->left);
}
Node * deleteNode(Node * root,int val){
    if(!root)
    return NULL;
    if(root-> data == val){
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        else if(root->left && !root->right){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right){
            Node * temp = root->right;
            delete root;
            return temp;
        }
        else{
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right= deleteNode(root->right,mini);
            return root;
        }
    }else if(root->data > val){
        root->right= deleteNode(root->right,val);
    }else{
        root->left = deleteNode(root->left, val);
    }
}
Node * insertNode(Node * root,int val){
    if(!root){
    root = new Node(val);
    return root;
    }

    if(val > root->data)
    root->right = insertNode(root->right,val);
    else
    root->left = insertNode(root->left,val);

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
void buildBST(Node *&root){
    int data;
    cout << "Enter the root "<< endl;
    cin >> data;
    while(data != -1){
        root = insertNode(root,data);
        cout << "Enter the data : ";
        cin >> data;
    }
}
int main(){

     Node * root = NULL;
    buildBST(root);
    levelOrderTrans(root);

    return 0;

}