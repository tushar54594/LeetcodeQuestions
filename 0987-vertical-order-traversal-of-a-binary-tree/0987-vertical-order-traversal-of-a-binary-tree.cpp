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
    void preorder(TreeNode* root, map<int, vector<pair<int,int>>> &m, int level, int verticalNo)
    {
        if(root == NULL) return;
        
        m[verticalNo].push_back({level, root->val});
        preorder(root->left, m, level+1, verticalNo-1);
        preorder(root->right, m, level+1, verticalNo+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> m;
        preorder(root, m, 0, 0);
        
        vector<vector<int>> ans;
        for(auto a : m)
        {
            sort(a.second.begin(), a.second.end()); //sort the vertical order of same level nodes
            vector<int> temp;
            for(auto pair : a.second)
                temp.push_back(pair.second);
            
            ans.push_back(temp);
        }
        return ans;
    }
};

/*
take a map : key => vertical line , value => vector of pair{level, node->value}  
*/