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
    
    int solve(TreeNode* root, unordered_map<TreeNode*, int> &dp){
        if(root == NULL) return 0;
        
        if(dp.count(root)) return dp[root];
        
        int ans_taking_root = root->val;
        if(root->left) ans_taking_root += solve(root->left->left, dp) + solve(root->left->right, dp);
        if(root->right) ans_taking_root += solve(root->right->left, dp) + solve(root->right->right, dp);
        
        int ans_not_taking_root = solve(root->left, dp) + solve(root->right, dp);
        
        return dp[root] = max(ans_taking_root, ans_not_taking_root);
    }
    
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solve(root, dp);
    }
};

/*
We have 2 choices
1. Rob the root house and skip it's children and move on to root's grandchildren
2. Skip the root house and move on to left and right_subtree, with the hope that it will yeild better result
*/