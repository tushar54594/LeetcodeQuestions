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
    TreeNode* find(TreeNode* root)
    {
        if(root->right == NULL)
            return root;
        
        return find(root->right);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        //we have to delete the node if found. so if we keep searching for the node and we reach null, this means the node is not found and we return the original tree
        if(root == NULL)
            return root;
        //the node to be deleted is found
        else if(root->val == key)
        {
            //the node is a leaf node
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            //if the node has both left and right child
            else if(root->left != NULL && root->right != NULL)
            {
                //go to the left subtree and find the largest element in the left subtree
                TreeNode* temp = find(root->left);
                //replace the value of the node with this largest element found in the previous step
                root->val = temp->val;
                //call the deleteNode function to delete this largest element since it will be present 2 times
                root->left = deleteNode(root->left, root->val);
            }
            //node has only left child
            else if(root->left != NULL)
            {
                TreeNode* x = root->left;
                delete root;
                return x;
            }
            //node has only right child
            else
            {
                TreeNode* x = root->right;
                delete root;
                return x;
            }
            
        }
        //the node to be deleted is not found
        else
        {
            if(key < root->val)
                root->left = deleteNode(root->left, key);
            else
                root->right = deleteNode(root->right, key);
        }
        return root;
    }
};