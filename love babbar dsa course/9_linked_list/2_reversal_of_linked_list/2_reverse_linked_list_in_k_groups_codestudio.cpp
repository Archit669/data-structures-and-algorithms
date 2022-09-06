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

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    // base case
    while (b[0] == 0 && n!=0) {b++;  n--;}
	if (head == NULL || n == 0) return head;
    
    // we will reverse the linked list of size k
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = head->next;
    int count = 0;
    
    while (count < b[0] && curr!= NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    
    // recursion will come with reversed list with k-group
     head->next = getListAfterReverseOperation(curr, n-1, b+1);    
    
    return prev;
}