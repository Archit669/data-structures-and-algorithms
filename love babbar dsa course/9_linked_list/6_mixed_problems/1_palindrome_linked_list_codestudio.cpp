#include <bits/stdc++.h>
using namespace std;

//  Following is the class structure of the LinkedListNode class:

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
LinkedListNode<int> *middleOfLinkedList(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head->next;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
        return 1;
    LinkedListNode<int> *l1 = head;
    LinkedListNode<int> *mid = middleOfLinkedList(head);
    LinkedListNode<int> *l2 = mid->next;
    mid->next = NULL;
    l2 = reverse(l2);

    while (l1 && l2)
    {
        if (l1->data == l2->data)
        {
            l1 = l1->next;
            l2 = l2->next;
        }
        else
        {
            return 0;
        }
    }

    return 1;
}