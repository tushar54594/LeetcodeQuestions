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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        //move fast by n steps
        while(n--)
            fast = fast->next;
        
        //look at the second example test case i.e we have to delete the first node
        if(fast == NULL)
        {
            ListNode* temp = head;
            head = head->next;
			temp->next = NULL;
            delete temp;
            return head;
        }
        
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        //now slow will point to one node previous to the node to be deleted
        ListNode *temp = slow->next; //the node to be deleted
        slow->next = slow->next->next;
        delete temp;
        
        return head;
    }
};