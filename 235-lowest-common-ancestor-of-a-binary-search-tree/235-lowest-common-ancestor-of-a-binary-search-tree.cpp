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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        //both the values of p and q are lesser than the root value, thus we move left
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        //both the values of p and q are greater than the root value, thus we move right
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p , q);
        
        return root;
    }
};