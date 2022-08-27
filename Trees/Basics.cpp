// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<typename T>  
class TreeNode{
  public :
  T data;
  vector< TreeNode *> childern;
  TreeNode(T data){
      this->data= data;
  }
};
TreeNode <int> * levelOrderInput(){
    int data;
    cout << "Enter the data for Root Node: " << endl;
    cin >> data;
    TreeNode<int> * root = new TreeNode<int>(data);
    
    queue<TreeNode<int> *> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int> * front = q.front();
        q.pop();
        
        int n;
        cout << "Enter the number of children's of Node "<<front->data<<" : ";
        cin >> n;
        
        for(int i =0 ; i<n;i++){
            cout << "Enter the "<<i+1<< " child of node "<<front->data<<" : "<<endl;
            cin >> data;
            TreeNode<int>* child = new TreeNode<int>(data);
            front->childern.push_back(child);
            q.push(child);
        }
    }
    return root;
}
void printLevelOrder(TreeNode<int>* root){
    if(!root)
    return;
    
    queue <TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int> * front = q.front();
        q.pop();
        
        while(front->children)
    }
    
}

int main() {
    
    TreeNode <int> * root = levelOrderInput();
    
    return 0;
}