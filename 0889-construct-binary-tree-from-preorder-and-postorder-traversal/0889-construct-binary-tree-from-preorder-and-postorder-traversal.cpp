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
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd)
    {
        if(preStart > preEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        if(preStart == preEnd) return root; //***VVI(So that index does not go out of bound in preStart+1)
        
        int postIndex = -1;
        for(int i=postStart; i<=postEnd; i++)
        {
            if(postorder[i] == preorder[preStart+1])
            {
                postIndex = i;
                break;
            }
        }
        
        int len = postIndex - postStart + 1;
        
        int leftPreStart = preStart + 1;
        int leftPreEnd = preStart + len;
        int rightPreStart = preStart + len + 1;
        int rightPreEnd = preEnd;
        
        int leftPostStart = postStart;
        int leftPostEnd = postIndex;
        int rightPostStart = leftPostEnd + 1;
        int rightPostEnd = postEnd - 1;
        
        root->left = helper(preorder, postorder, leftPreStart, leftPreEnd, leftPostStart, leftPostEnd);
        root->right = helper(preorder, postorder, rightPreStart, rightPreEnd, rightPostStart, rightPostEnd);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preStart = 0;
        int preEnd = preorder.size()-1;
        int postStart = 0;
        int postEnd = postorder.size()-1;
        
        return helper(preorder, postorder, preStart, preEnd, postStart, postEnd);
    }
};

/*
Eg preorder = [1,2,4,5,3,6,7]   (NLR)
   postorder = [4,5,2,6,7,3,1]  (LRN)
In preorder, 1 will be root
and 2 will be root of the left subtree
and in postorder we find 2 and till 2, the part will be of left subtree
*/