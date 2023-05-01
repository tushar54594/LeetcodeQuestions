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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        
        if(lh == rh)
            return pow(2,lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int findLeftHeight(TreeNode* root)
    {
        int height = 0;
        while(root != NULL)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    
    int findRightHeight(TreeNode* root)
    {
        int height = 0;
        while(root != NULL)
        {
            height++;
            root = root->right;
        }
        return height;
    }
};

/*
1.Formula is (2^TreeLevel - 1). Only works for perfect tree.
2.To determine if its a perfect tree, go all the way down and count the nodes on left and right side, If they match, its a perfect tree and our formula applies.
3.If its not a perfect tree, we go on left and right subtree and again determine if they are perfect tree.
4.When we have our left and right heights, we do (1 + left + right)
5.If we reach null, return 0
*/