#include <bits/stdc++.h>
using namespace std;

// Following is the linked list node structure:

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *deleteMiddle(Node<int> *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node<int> *slow = head;
    Node<int> *fast = head;
    Node<int> *prev = NULL;

    while (fast->next && fast->next->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL)
    {
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;
    }
    else
    {
        Node<int>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    return head;
}