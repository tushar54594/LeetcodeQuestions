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
    //NOTE: We are not passing string str as reference because we want it to be different for each step
    void solve(TreeNode* root, vector<string> &ans, string str)
    {
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(str);
            return;
        }
        
        if(root->left) solve(root->left, ans, str + "->" + to_string(root->left->val));
        if(root->right) solve(root->right, ans, str + "->" + to_string(root->right->val));
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;
        
        solve(root, ans, to_string(root->val));
        return ans;
    }
};

/*
insert the node value in an array
First go to left then right
if we get the leaf node, then return
while returning, make sure to remove the element from the array
*/