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
private:
    TreeNode* startNode = NULL;
    
    void makeParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent)
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
    
    void getStartNode(TreeNode* root, int start) {
        if(root == NULL) 
            return;
        if(start == root->val)
        {
            startNode = root;
            return;
        }
        getStartNode(root->left, start);
        getStartNode(root->right, start);
    }
    
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        makeParents(root, parent);
        getStartNode(root, start);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;
        
        int time = 0;
        while(!q.empty())
        {
            int n = q.size();
            int flag = 0;
            
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                    flag = 1;
                }
                if(node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                    flag = 1;
                }
                if(parent[node] && !visited[parent[node]])
                {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                    flag = 1;
                }
            }
            if(flag) time++;
        }
        
        return time;
    }
};