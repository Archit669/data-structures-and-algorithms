#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the LinkedListNode class:

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    LinkedListNode<int> *newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

LinkedListNode<int> *removeKthNode(LinkedListNode<int> *head, int K)
{
    head = reverse(head);
    int count = 1;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;

    while (curr != NULL && count < K)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == NULL || K == 0)
        return reverse(head);

    if (K == 1)
    {
        head = head->next;
    }
    else
    {
        prev->next = curr->next;
    }

    return reverse(head);
}