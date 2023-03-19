#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:

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

// find middle of linked list
Node* MiddleOfLinkedList(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// reverse a linked list
Node* reverse(Node* head){
    if (head == NULL || head->next == NULL) return head;
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// add two numbers 1 leetcode
Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *list1 = l1;
    Node *list2 = l2;
    Node *list3 = new Node(-1);
    Node *temp = list3;
    int carry = 0;

    while (list1 != NULL && list2 != NULL)
    {
        int sum = list1->data + list2->data + carry;
        temp->next = new Node(sum % 10);
        carry = sum / 10;
        temp = temp->next;
        list1 = list1->next;
        list2 = list2->next;
    }

    while (list1 != NULL)
    {
        int sum = list1->data + carry;
        temp->next = new Node(sum % 10);
        carry = sum / 10;
        temp = temp->next;
        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        int sum = list2->data + carry;
        temp->next = new Node(sum % 10);
        carry = sum / 10;
        temp = temp->next;
        list2 = list2->next;
    }

    if (carry)
    {
        temp->next = new Node(carry);
    }

    list3 = list3->next;
    return list3;
}

// add two numbers 2 leetcode
Node* addTwoLists(Node* first, Node* second) {
    while (first && first->data==0) first = first->next;
    while (second && second->data==0) second = second->next;
    
    if (first == NULL && second!= NULL) return second;
    if (second == NULL && first != NULL) return first;
    if (second == NULL && first == NULL){
        Node* ans = new Node(0);
        return ans;
    }
    
    Node* ans = addTwoNumbers(reverse(first),reverse(second));
    ans = reverse(ans);
    return ans;
}

// add first and second half
Node *addFirstAndSecondHalf(Node *head){
    if (head == NULL) return NULL;
    Node* Middle = MiddleOfLinkedList(head);
    Node* l1 = head;
    Node* l2 = Middle->next;
    Middle->next = NULL;
    
    Node* ans = addTwoLists(l1,l2);
    return ans;
}

