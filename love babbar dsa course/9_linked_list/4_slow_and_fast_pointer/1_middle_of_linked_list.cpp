
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

Node *findMiddle(Node *head) {
       Node* ptr1 = head;
       Node* ptr2 = head;
    
       while(ptr2!=NULL && ptr2->next!=NULL)
       {
           ptr1 = ptr1->next;
           ptr2 = ptr2->next->next;
       }
    
        return ptr1;
}