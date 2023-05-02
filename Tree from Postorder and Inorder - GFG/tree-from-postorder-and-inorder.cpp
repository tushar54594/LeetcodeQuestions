//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

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
Node* helper(int post[], int in[], int postorderStart, int postorderEnd, int inorderStart, int inorderEnd)
{
    if(inorderStart > inorderEnd) return NULL;
        
        int rootVal = post[postorderEnd];
        
        int rootIndex = -1;
        for(int i=inorderStart; i<=inorderEnd; i++)
        {
            if(in[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        }
        
        Node* root = new Node(rootVal);
        
        int leftInStart = inorderStart;
        int leftInEnd = rootIndex-1;
        int rightInStart = rootIndex+1;
        int rightInEnd = inorderEnd;
        
        int leftPostStart = postorderStart;
        /*leftInEnd - leftInStart = leftPreEnd - leftPreStart
          since inorder and preorder will have same no of elements
        */
        int leftPostEnd = leftInEnd-leftInStart+leftPostStart;
        int rightPostStart = leftPostEnd+1;
        int rightPostEnd = postorderEnd-1;
        
        root->left = helper(post, in, leftPostStart, leftPostEnd, leftInStart, leftInEnd);
        root->right = helper(post, in, rightPostStart, rightPostEnd, rightInStart, rightInEnd);
        
        return root;
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    int postorderStart = 0;
        int postorderEnd = n-1;
        int inorderStart = 0;
        int inorderEnd = n-1;
        
        return helper(post, in, postorderStart, postorderEnd, inorderStart, inorderEnd);
}
