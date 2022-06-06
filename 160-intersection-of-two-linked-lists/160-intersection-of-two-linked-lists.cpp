/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //function to get the intersection node
    ListNode *intersectionPoint(ListNode *headA, ListNode *headB, int x, int y)
    {
        if(x>=y)
        {
            int diff = x-y;
            while(diff != NULL)
            {
                headA = headA->next;
                diff--;
            }
            
            while(headA != headB)
            {   
                headA = headA->next;
                headB = headB->next;
            }
            return headA;
        }
        else
            return intersectionPoint(headB,headA, y, x);
    }
    
    //function to calculate the length of the linked list
    int count(ListNode* head)
    {
        int count = 0;
        while(head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int x = count(headA);
        int y = count(headB);
        return intersectionPoint(headA, headB, x, y);
    }
};