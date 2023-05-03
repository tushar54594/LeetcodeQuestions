/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "null";
        
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    } 

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return helper(ss);
    }
    
    TreeNode* helper(istringstream &ss)
    {
        string str;
        getline(ss, str, ',');
        
        if(str == "null") return NULL;
        
        TreeNode* root = new TreeNode(stoi(str));
        root->left = helper(ss);
        root->right = helper(ss);
        return root;
    }
};

/*
    1
2      3

ser : 1, (left), (right)
left : 2, null, null
right : 3, null, null

thus ser : 1, 2, null, null, 3, null, null
*/

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));