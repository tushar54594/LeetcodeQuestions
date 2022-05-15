/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        //if root is NULL then return null
        if(root == NULL)
            return NULL;
        //if root is equal to either of p or q, then the root will be our LCA
        if(root == p || root == q)
            return root;
        
        TreeNode* left = solve(root->left, p, q);
        TreeNode* right = solve(root->right, p, q);
        
        //both left and right are not null
        if(left != NULL && right != NULL)
            return root;
        //left is not null
        if(left != NULL)
            return left;
        //right is not null
        if(right != NULL)
            return right;
        
        //both left and right are null
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};