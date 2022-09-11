#include <bits/stdc++.h>
using namespace std;

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

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // create a dummy node
    Node<int> *dummy = new Node<int>(-1);

    // create tail of dummy node
    Node<int> *dummyTail = dummy;

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
