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
    TreeNode* helper(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return NULL;
        
        //find the mid value
        int mid = (start + end)/2;
        //create a new node with nums[mid] as it's value
        TreeNode* root = new TreeNode(nums[mid]);
        //construct the left part of BST
        root->left = helper(nums, start, mid-1);
        //construct the right part of BST
        root->right = helper(nums, mid+1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};