/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Normally we cannot delete the present node with out having the prevoius pointer
        // Now we are not having the previous pointer 
        
        // so copy the value of next node to the present node and delete the next node
        // This solves our problem
        
        ListNode* temp=node->next; // storing next node (for deleting at the end)
        node->val=node->next->val; // change the present node value with the next node's value
        node->next=node->next->next; // delete the next node
        delete temp; 
    }
};