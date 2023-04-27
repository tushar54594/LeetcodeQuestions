//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    void insertAtTail(Node* &tail, Node* curr)
    {
        tail->next = curr;
        tail = curr;
    }
    
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head == NULL || head->next == NULL) return head;
        
        Node *zeroHead = new Node(-1);
        Node *zeroTail = zeroHead;
        Node *oneHead = new Node(-1);
        Node *oneTail = oneHead;
        Node *twoHead = new Node(-1);
        Node *twoTail = twoHead;
        
        //create 3 linked lists
        Node *curr = head;
        while(curr != NULL)
        {
            int val = curr->data;
            
            if(val == 0) insertAtTail(zeroTail, curr);
            else if(val == 1) insertAtTail(oneTail, curr);
            else insertAtTail(twoTail, curr);
            
            curr = curr->next;
        }
        
        //merge 3 sublists
        
        //1s list is not empty
        if(oneHead->next != NULL)
        {
            zeroTail->next = oneHead->next;
            oneTail->next = twoHead->next;
        }
        else //empty
            zeroTail->next = twoHead->next;
        
        twoTail->next = NULL;
        
        head = zeroHead->next;
        delete(zeroHead);
        delete(oneHead);
        delete(twoHead);
        
        return head;
    }
};

/*
Make 3 linked lists for zero, one and two
Merge all three linked lists
*/


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends