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
    int solve(TreeNode* root, bool &flag)
    {
        if(root == NULL)
            return 0;
            
        //leaf node
        if(root->left == NULL && root->right == NULL)
            return root->val;
            
        int leftSum = solve(root->left, flag);
        int rightSum = solve(root->right, flag);
        int sum = leftSum + rightSum;
        
        if(root->val != sum)
            flag = false;
        
        return sum + root->val;
    }
    
    bool checkTree(TreeNode* root) {
        bool flag = true;
        int x = solve(root, flag);
        return flag;
    }
};