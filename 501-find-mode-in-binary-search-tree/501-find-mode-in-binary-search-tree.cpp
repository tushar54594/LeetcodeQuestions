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
    map<int, int> m;
    
    int max = INT_MIN;
    void inorder(TreeNode* root, vector<int> &arr)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, arr);
        m[root->val]++;
        if(m[root->val] > max)
            max = m[root->val];
        inorder(root->right, arr);
    }
    
    vector<int> findMode(TreeNode* root) {
        inorder(root, arr);
        vector<int> ans;
        
        for(auto i : m)
        {
            if(i.second == max)
                ans.push_back(i.first);
        }
        return ans;
    }
};