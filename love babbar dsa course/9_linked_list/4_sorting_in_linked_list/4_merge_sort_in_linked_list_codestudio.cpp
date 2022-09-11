#include <bits/stdc++.h>
using namespace std;

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

Node *middleOfLinkedList(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast!= NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow= slow->next;
    }
    
   return slow;
}

Node *sortTwoLists(Node *first, Node *second)
{
    // edge cases
    if (first == NULL) return second;
    if (second == NULL) return first;
    
    // create a dummy node
    Node *dummy = new Node(-1);

    // create tail of dummy node
    Node *dummyTail = dummy;

    // while first and second are not null
    while (first != NULL && second != NULL)
    {

        // if first element is less than or equal to second element
        if (first->data <= second->data)
        {
            dummyTail->next = first;
            first = first->next;
        }
        // if second element is less than first element
        else
        {
            dummyTail->next = second;
            second = second->next;
        }

        // move tail of dummy linked list
        dummyTail = dummyTail->next;
        dummyTail->next = NULL;
    }

    // if first linked list has element than connect it to dummy linked list
    if (first)
    {
        dummyTail->next = first;
    }
    // if second linked list has element than connect it to dummy linked list
    else
    {
        dummyTail->next = second;
    }

    // return ans
    return dummy->next;
}


Node *sortLL(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL) return head;
    
    Node* mid = middleOfLinkedList(head);
    
    
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    
    left = sortLL(left);
    right = sortLL(right);
    
    head = sortTwoLists(left,right);
    
    return head;
}
