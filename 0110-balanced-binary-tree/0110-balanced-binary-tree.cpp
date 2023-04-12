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
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int left = height(root->left);
        int right = height(root->right);
        
        if(abs(left-right) > 1) return false;
        
        //if it comes here, it means root node balanced, check for left and right subtrees
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if(!l || !r) return false;
        
        return true;
    }
};

//A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.
//the difference between the heights of the two sub trees are not bigger than 1, and both the left sub tree and right sub tree are also balanced