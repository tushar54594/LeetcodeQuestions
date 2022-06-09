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
    vector<int> ans;
    //inorder: sorts in ascending order
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int s = 0;
        int e = ans.size()-1;
        while(s<e)
        {
            if(ans[s] + ans[e] == k)
                return true;
            else if(ans[s] + ans[e] > k)
                e--;
            else
                s++;
        }
        return false;
    }
};