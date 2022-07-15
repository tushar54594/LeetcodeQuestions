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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        
        while(curr != NULL)
        {
            while(curr != NULL && curr->val == val)
            {
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                temp->next = NULL;
                delete temp;
            }
            prev = curr;
            if(curr != NULL)
                curr = curr->next;
        }
        return dummy->next;
    }
};