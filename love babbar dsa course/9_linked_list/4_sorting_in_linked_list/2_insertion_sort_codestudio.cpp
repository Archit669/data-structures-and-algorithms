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

Node* insertionSortLL(Node *head)
{
    Node* dummy = new Node(-1);
    
    while(head != NULL){
        Node* temp = dummy;
        while(temp->next != NULL && temp->next->data <= head->data){
            temp = temp->next;
        }
        
        Node* forward = head->next;
        head->next = NULL;
        
        head->next = temp->next;
        temp->next = head;
        
        head = forward;  
    }
    
    return dummy->next;
}
