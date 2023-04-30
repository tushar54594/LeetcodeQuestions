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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<pair<TreeNode*, int>> q; //{node, index}
        q.push({root, 0});
        
        long long int ans = 0;
        while(!q.empty())
        {
            int n = q.size();
            long long int start = q.front().second;
            long long int end = q.back().second;
            ans = max(ans, end - start + 1);
            for(int i=0; i<n; i++)
            {
                auto p = q.front();
                q.pop();
                
                TreeNode* node = p.first;
                long long int index = p.second;
                
                if(node->left) q.push({node->left, 2*index+1});
                if(node->right) q.push({node->right, 2*index+2});
            }
        }
        return ans;
    }
};

/*
We give indexes to the nodes
initially root index will be 0

if parent index = i
then
left child index = 2*i+1
right child index = 2*i + 2

for every level, max width = lastIndex - firstIndex + 1

Do level order traversal
in queue, store node and it's index
*/