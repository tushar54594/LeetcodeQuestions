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
    vector<int> arr;
    int i = 0;
    void inorder(TreeNode* root)
    {        
        if(root == NULL)
            return;
        
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    void helper(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        helper(root->left);
        if(root->val != arr[i])
            swap(root->val, arr[i]);
        i++;
        helper(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(arr.begin(), arr.end());
        helper(root);
    }
};