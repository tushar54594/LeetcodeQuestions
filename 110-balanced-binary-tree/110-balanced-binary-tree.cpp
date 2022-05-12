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
    bool ans = true;
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        if(abs(lh - rh) > 1)
            ans = false;
        
        return 1 + max(lh,rh);
    }
    
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        
        return ans;
    }
};