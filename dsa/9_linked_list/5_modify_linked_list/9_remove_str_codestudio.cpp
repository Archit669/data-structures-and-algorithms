#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity :  O(N * K)
    Space Complexity : O(1)

    Where 'N' is the total length of linked list.
    Where 'K' is the length of the string.
*/


// Following is the class structure of the Node class:

class Node
{
public:
    char data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


Node *removeStr(Node *head, string str)
{
    if (str.length() == 0)
        return head;
    if (head == NULL)
        return NULL;
    head->next = removeStr(head->next, str);
    Node *temp = head;
    int ptr1 = 0;
    while (temp != NULL && ptr1 < str.length() && temp->data == str[ptr1])
    {
        temp = temp->next;
        ptr1++;
    }

    return (ptr1 >= str.length()) ? temp : head;
}