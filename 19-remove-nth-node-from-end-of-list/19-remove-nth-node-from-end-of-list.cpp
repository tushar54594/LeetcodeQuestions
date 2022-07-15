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
    int length(ListNode* head)
    {
        int count = 0;
        while(head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //nth node from end == n-k+1 node from the beginning
        if(head == NULL || head->next == NULL)
            return NULL;
        
        int l = length(head);
        
        //the node to be deleted is the head
        if(l == n)
        {
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        for(int i=0; i<(l-n+1)-1; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if(prev != NULL && curr != NULL)
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        return head;
    }
};