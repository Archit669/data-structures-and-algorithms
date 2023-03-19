#include <bits/stdc++.h>
using namespace std;

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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

Node *getListAfterDeleteOperation(Node *head)
{
    head = reverse(head);
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL && curr->next != NULL)
    {
        Node *forward = curr->next;
        if (curr->data < forward->data)
        {
            if (prev == NULL)
            {
                head = head->next;
                curr->next = NULL;
                delete curr;
                curr = head;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                curr = forward;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    head = reverse(head);
    return head;
}
