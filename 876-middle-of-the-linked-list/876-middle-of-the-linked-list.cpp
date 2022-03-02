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
        ListNode* t = head;
        int count = 0;
        while(t != NULL){
            count++;
            t = t->next;
        }
        
        int mid = count/2;
        ListNode* temp = head;
        count = 0;
        while(count < mid){
            temp = temp->next;
            count++;
        }
        return temp;
        
    }
};