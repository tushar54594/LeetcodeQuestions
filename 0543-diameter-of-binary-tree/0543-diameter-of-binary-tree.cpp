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
    int height(TreeNode* root, int &diameter) {
        //base case
        if(root == NULL)
            return 0;
        
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        diameter = max(diameter, lh + rh);
        //+1 is not required here, because the question(on leetcode) says diameter as number of edges. And in a tree, the number of edges are one less than the number of nodes. So it works fine
        return 1 + max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }
};