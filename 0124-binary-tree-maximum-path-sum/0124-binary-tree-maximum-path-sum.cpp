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
    int maxPath(TreeNode* root, int &maxi)
    {
        if(root == NULL)
            return 0;
        
        int maxLeftSum = maxPath(root->left, maxi);
        if(maxLeftSum < 0)
            maxLeftSum = 0;
        
        int maxRightSum = maxPath(root->right, maxi);
        if(maxRightSum < 0)
            maxRightSum = 0;
        
        //ans for every node will be root->val + maxLeftSum + maxRightSum
        maxi = max(maxi, root->val + maxLeftSum + maxRightSum); 
        
        return root->val + max(maxLeftSum,maxRightSum); //konsa path lena hai uske liye hai ye
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
};