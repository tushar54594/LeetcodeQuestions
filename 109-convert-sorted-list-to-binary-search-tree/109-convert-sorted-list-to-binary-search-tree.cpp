/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
        {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        
        //find the mid 
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* previous = NULL;
        while(fast != NULL && fast->next != NULL)
        {
            previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        previous->next = NULL; //Using this we are creating two separate linked lists 
        
        //create a new node with the mid value as it's value
        TreeNode* root = new TreeNode(slow->val);
        
        //Create the left part of the BST
        root->left = sortedListToBST(head);
        //Create the right part of the BST
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};