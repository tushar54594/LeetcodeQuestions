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
    ListNode* middleNode(ListNode* head) {
        //for empty list or list with only 1 node
        if(head == NULL || head->next == NULL){
            return head;
        }
        // for list with 2 nodes
        else if(head->next->next == NULL){
            return head->next;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL){
            slow = slow->next;
            if(fast->next == NULL)
                fast = fast->next;
            else
                fast = fast->next->next;
        }
        return slow;
    }
};