/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd)
    {
        if(inorderStart > inorderEnd)
            return NULL;
        
        int rootVal = preorder[preorderStart];
        
        int rootIndex = -1;
        for(int i=inorderStart; i<=inorderEnd; i++)
        {
            if(rootVal == inorder[i])
            {
                rootIndex = i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(rootVal);
        
        int leftInStart = inorderStart;
        int leftInEnd = rootIndex-1;
        int rightInStart = rootIndex+1;
        int rightInEnd = inorderEnd;
        
        int leftPreStart = preorderStart+1;
        /*leftInEnd - leftInStart = leftPreEnd - leftPreStart
          since inorder and preorder will have same no of elements
        */
        int leftPreEnd = leftInEnd-leftInStart+leftPreStart;
        int rightPreStart = leftPreEnd+1;
        int rightPreEnd = preorderEnd;
        
        root->left = helper(preorder, inorder, leftPreStart, leftPreEnd, leftInStart, leftInEnd);
        root->right = helper(preorder, inorder, rightPreStart, rightPreEnd, rightInStart, rightInEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderStart = 0;
        int preorderEnd = preorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        
        return helper(preorder, inorder, preorderStart, preorderEnd, inorderStart, inorderEnd);
    }
};