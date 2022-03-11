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
    ListNode* solve(ListNode* list1, ListNode* list2){
        ListNode* prev = list1;
        ListNode* curr = prev->next;
        ListNode* temp = list2;
        ListNode* next2 = NULL;
        
        while(curr != NULL && temp != NULL){
            
            if(temp->val >= prev->val && temp->val <= curr->val){
                prev->next = temp;
                next2 = temp->next;
                temp->next = curr;
                
                prev = temp;
                temp = next2;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        
        if(curr == NULL){
            prev->next = temp;
            return list1;
        }
        
        return list1;
    }
    
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        if(list1->val <= list2->val)
            return solve(list1,list2);
        else
            return solve(list2,list1);
    }
};