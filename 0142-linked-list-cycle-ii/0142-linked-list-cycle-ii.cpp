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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL){
            slow = slow->next;
            if(fast->next == NULL)
                fast = fast->next;
            else
                fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        
        if(fast == NULL)  //loop nahi hai
            return NULL;
        
        while(slow != head){
            slow = slow->next;
            head = head->next;
        }
        return head;
        
    }
};