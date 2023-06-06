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
    void dfs(TreeNode* root, int targetSum, long long int sum, unordered_map<long long int, int> &m, int &ans)
    {
        if(root == NULL) return;
        
        sum += root->val;
        if(sum == targetSum) ans++;
        if(m.find(sum - targetSum) != m.end()) ans += m[sum - targetSum];
        
        m[sum]++;
        dfs(root->left, targetSum, sum, m, ans);
        dfs(root->right, targetSum, sum, m, ans);
        
        m[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long int, int> m;
        int ans = 0;
        
        dfs(root, targetSum, 0, m, ans);
        return ans;
    }
};