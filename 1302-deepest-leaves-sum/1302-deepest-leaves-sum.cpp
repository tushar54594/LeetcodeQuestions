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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        
        // we visit each depth level one by one. Just reset sum to 0 at start of each depth level and add the               values of all nodes on that level. At the end, sum will store the sum of all values of the last level or           the sum of values or deepest leaves.
        while(!q.empty())
        {
            sum = 0;
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                sum = sum + node->val;
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                
            }
        }
        return sum;
    }
};