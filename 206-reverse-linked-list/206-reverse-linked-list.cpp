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
    void reverse(ListNode* &head, ListNode* &prev, ListNode* &curr){
        //base case
        if(curr == NULL){
            head = prev;
            return;
        }
        
        reverse(head,curr,curr->next); //since in the next iteration, prev = curr and curr = curr->next
        curr->next = prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* prev = NULL;
       ListNode* curr = head;
       reverse(head,prev,curr);
       return head;
    }
};