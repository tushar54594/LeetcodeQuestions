class Solution {

  void insert_Node(int data, ListNode* &first, ListNode* &last){

ListNode *node = new ListNode();
node->val = data;
node->next=NULL;

if(first==NULL){
first = node;
last=node;
}
 
 else{
 last->next = node;
 last = node;
 }
  }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
ListNode * first=NULL;
ListNode * last=NULL;
int carry=0;

while(l1!=NULL && l2!=NULL){

int sum = l1->val + l2->val + carry;
int digit = sum%10;
carry = sum/10;
insert_Node(digit,first,last);
l1=l1->next;
l2=l2->next;
}
        
while(l1!=NULL){

int sum = l1->val  + carry;
int digit = sum%10;
carry = sum/10;
insert_Node(digit,first,last);
l1=l1->next;
}

while(l2!=NULL){

int sum = l2->val  + carry;
int digit = sum%10;
carry = sum/10;
insert_Node(digit,first,last);
l2=l2->next;
}

while(carry!=0){

int digit = carry%10;
carry = carry/10;
insert_Node(digit,first,last);
}

return first;
    }
};