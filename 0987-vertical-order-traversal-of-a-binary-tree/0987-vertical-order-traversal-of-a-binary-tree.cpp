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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        //node col row
        map<int, map<int, multiset<int>>> m;
        
        q.push({root, {0, 0}});
        
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0; i<s; i++)
            {
                auto a = q.front();
                q.pop();
                
                auto node = a.first;
                int x = a.second.first; //col
                int y = a.second.second; //row
                
                m[x][y].insert(node->val);
                
                if(node->left) q.push({node->left, {x-1, y+1}});
                if(node->right) q.push({node->right, {x+1, y+1}});
            }
        }
        
        for(auto x : m)
        {
            vector<int> v;
            for(auto y : x.second)
            {
                for(auto z : y.second) v.push_back(z);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};