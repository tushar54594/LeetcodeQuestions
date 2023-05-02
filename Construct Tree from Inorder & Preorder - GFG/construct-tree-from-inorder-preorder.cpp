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
    Node* helper(int pre[],int in[], int preorderStart, int preorderEnd, int inorderStart, int inorderEnd)
    {
        if(inorderStart > inorderEnd) return NULL;
        
        int rootVal = pre[preorderStart];
        
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
        
        int leftPreStart = preorderStart+1;
        int leftPreEnd = leftInEnd - leftInStart + leftPreStart;
        int rightPreStart = leftPreEnd+1;
        int rightPreEnd = preorderEnd;
        
        root->left = helper(pre, in, leftPreStart, leftPreEnd, leftInStart, leftInEnd);
        root->right = helper(pre, in, rightPreStart, rightPreEnd, rightInStart, rightInEnd);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderStart = 0;
        int preorderEnd = n-1;
        int inorderStart = 0;
        int inorderEnd = n-1;
        
        return helper(pre, in, preorderStart, preorderEnd, inorderStart, inorderEnd);
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