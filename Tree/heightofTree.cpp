#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
Node * buildTree(Node * root){
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
    return root;
}
class Solution{
    public:
    int height(struct Node* node){
        if(!node )
        return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        int res = max(left,right) +1;
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        Node * root = NULL;
		Node * root = buildTree(root);
        Solution ob;
		cout<<ob.height(root)<<endl;
    }
    return 0;
}
// } Driver Code Ends