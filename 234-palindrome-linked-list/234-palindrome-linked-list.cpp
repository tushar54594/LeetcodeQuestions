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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            slow = slow->next;
            if(fast->next == NULL)
                fast = fast->next;
            else
                fast = fast->next->next;
        }
        return slow;
    }
    
public:
    ListNode* reverse(ListNode* head){
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
    
    bool compareList(ListNode *head1, ListNode *head2) {
        while (head1 != NULL) {
            if (head1->val!=head2->val)
                return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        //single element
        if(head->next == NULL)
            return true;
        ListNode* mid = middleNode(head);
        ListNode* reversed = reverse(mid);
        
        return compareList(reversed,head);
        
    }
};

//Time Complexity: O(n)
// Space Complexity: O(1)