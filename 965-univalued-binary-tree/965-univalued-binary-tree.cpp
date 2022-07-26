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
    int ans = true;
    void inorder(TreeNode* root, int value)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, value);
        if(root->val != value)
        {
            ans = false;
            return;
        }
        inorder(root->right, value);
        
    }
    
    bool isUnivalTree(TreeNode* root) {
        int value = root->val;
        inorder(root, value);
        return ans;
    }
};