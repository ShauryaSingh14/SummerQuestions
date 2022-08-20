//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    void mapping(int in[], map<int,int> &m,int n){
        for(int i =0 ; i< n ;i++){
            m[in[i]]=i;
        }
    }
    Node * constr(int in[], int pre[], int &preIdx, int n, 
                   int stIdx, int enIdx, map<int,int> &m){
        
        if(preIdx >= n || stIdx > enIdx )
        return NULL;
        
        int element = pre[preIdx++];
        Node * root = new Node(element);
        int pos = m[element];
        
        root ->left = constr(in,pre,preIdx,n,stIdx,pos-1,m);
        root ->right = constr(in,pre,preIdx,n,pos+1,enIdx,m);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIdx =0;
        map <int,int> m;
        mapping(in,m, n);
        Node * root = constr(in,pre,preIdx,n,0,n-1,m);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends