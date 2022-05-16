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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
            return new TreeNode(val);
        
        //since we have to return the value of root at last, thus we create a copy of the root
        TreeNode* curr = root;
        while(true)
        {
            //if the val to be inserted is lesser than the node, then we have to move left. If the left is null then we create a new node and insert the node in the left
            if(val < curr->val)
            {
                if(curr->left != NULL)
                    curr = curr->left;
                else
                {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(curr->right != NULL)
                    curr = curr->right;
                else
                {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};