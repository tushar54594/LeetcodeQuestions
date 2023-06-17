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
    void preorder(TreeNode* root, int maxValue, int &ans)
    {
        if(root == NULL) return;
        
        if(root->val >= maxValue)
        {
            ans++;
            maxValue = root->val;
        }
        
        preorder(root->left, maxValue, ans);
        preorder(root->right, maxValue, ans);
    }
    
    int goodNodes(TreeNode* root) {
        int ans = 0;
        preorder(root, INT_MIN, ans);
        return ans;
    }
};