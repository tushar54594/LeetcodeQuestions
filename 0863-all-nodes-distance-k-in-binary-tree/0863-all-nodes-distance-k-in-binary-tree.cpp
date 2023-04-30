/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int distance = 0;
        while(!q.empty())
        {
            int n = q.size();
            
            if(distance == k) break;
            distance++;
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]])
                {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            ans.push_back(node->val);
        }
        
        return ans;
    }
};

/*
1.Mark each node to its parent to traverse upwards
2.We will do a BFS traversal starting from the target node
3.As long as we have not seen our node previously, Traverse up, left, right until reached Kth distance
4.When reached Kth distance, break out of BFS loop and remaining node's values in our queue is our result

****We basically turned a Binary Tree into an Undirected Graph
*/