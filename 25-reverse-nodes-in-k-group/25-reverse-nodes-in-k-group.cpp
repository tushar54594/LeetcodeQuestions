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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == NULL) 
                return head;
            cursor = cursor->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int count = 0;
        while(curr != NULL and count < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        
        if(forward != NULL)
            head->next = reverseKGroup(forward,k);
        
        return prev;
    }
};