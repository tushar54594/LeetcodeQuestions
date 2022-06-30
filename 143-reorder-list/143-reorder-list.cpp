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
    ListNode* reverseList(ListNode* head) {
        // in case of empty list or single node
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        //step1
        //find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //step2
        //split the linked list and reverse the second part
        ListNode* first = head;
        ListNode* second = reverseList(slow->next);
        slow->next = NULL;
        
        //step3
        //merging the two linked lists
        
        while(second) //since second list can be shorter when the LL length is odd
        {
            ListNode* temp1 = first->next;
            first->next = second;
            ListNode* temp2 = second->next;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
        
    }
};