#include <bits/stdc++.h>
using namespace std;
void funint(int fun){
    while(fun){
        fun= fun->right;
        fun->data= fun->data;
    }
    return  fun;
}
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
void createMapping(int in[],map <int,int>& m,int n){
    for(int i =0 ; i< n ;i++){
        m[in[i]]=i;
    }
}
Node * constr(int in[], int post[], int n, int& idx,
               int startIdx, int endIdx, map<int,int>&m){
    if(idx<0 || startIdx > endIdx)
    return NULL;
    
    int ele = post[idx--];
    Node * root = new Node(ele);
    
    int pos = m[ele];
    
    root->right = constr(in, post, n, idx,pos+1,endIdx,m);
    root->left = constr(in, post, n, idx, startIdx,pos-1,m);

    return root;
    
    }
Node *buildTree(int in[], int post[], int n) {
    int postIdx = n-1;
    map <int,int> m;
    createMapping(in,m,n);
    Node * root = constr(in,post,n,postIdx,0,n-1,m);
    return root;
}
