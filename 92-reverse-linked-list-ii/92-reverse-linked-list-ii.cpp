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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL)
            return head;
        
        //create a dummy node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        //till the leftmost index
        ListNode* prevO = NULL;
        ListNode* currO = dummy;
        for(int i=0; i<left; i++)
        {
            prevO = currO;
            currO = currO->next;
        }
        
        //reverse logic
        ListNode* prev = prevO;
        ListNode* curr = currO;
        
        for(int i=left; i<=right; i++)
        {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        //connect
        prevO->next = prev;
        currO->next = curr;
        
        return dummy->next;
        
    }
};