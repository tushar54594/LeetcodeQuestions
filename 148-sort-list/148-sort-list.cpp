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
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode *temp = NULL;
        while(fast != NULL){
            temp = slow;
            slow = slow->next;
            if(fast->next == NULL)
                fast = fast->next;
            else
                fast = fast->next->next;
        }
        temp -> next = NULL; 
        return slow;
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while(left != NULL && right != NULL){
            if(left->val < right->val){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while(left != NULL){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right != NULL){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        //base case
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* mid = getMid(head);
        
        ListNode* left = head;
        ListNode* right = mid;
        
        //recursive calls to sort both halves
        left = sortList(left);
        right = sortList(right);
        
        //merge both left and right halves
        return merge(left,right);
        
    }
};