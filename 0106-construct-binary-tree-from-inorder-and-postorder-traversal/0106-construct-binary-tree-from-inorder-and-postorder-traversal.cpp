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
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int postorderStart, int postorderEnd, int inorderStart, int inorderEnd)
    {
        if(inorderStart > inorderEnd) return NULL;
        
        int rootVal = postorder[postorderEnd];
        
        int rootIndex = -1;
        for(int i=inorderStart; i<=inorderEnd; i++)
        {
            if(inorder[i] == rootVal)
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
        
        int leftPostStart = postorderStart;
        /*leftInEnd - leftInStart = leftPreEnd - leftPreStart
          since inorder and preorder will have same no of elements
        */
        int leftPostEnd = leftInEnd-leftInStart+leftPostStart;
        int rightPostStart = leftPostEnd+1;
        int rightPostEnd = postorderEnd-1;
        
        root->left = helper(postorder, inorder, leftPostStart, leftPostEnd, leftInStart, leftInEnd);
        root->right = helper(postorder, inorder, rightPostStart, rightPostEnd, rightInStart, rightInEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderStart = 0;
        int postorderEnd = postorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        
        return helper(postorder, inorder, postorderStart, postorderEnd, inorderStart, inorderEnd);
    }
};