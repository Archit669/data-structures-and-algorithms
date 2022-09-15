#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *child;

    Node(T data)
    {
        this->data = data;
        next = NULL;
        child = NULL;
    }
};

Node<int> *flattenMultiLinkedList(Node<int> *head)
{
    if (head == NULL)
        return NULL;
    queue<Node<int> *> q;
    q.push(head);
    Node<int> *prev = NULL;
    while (!q.empty())
    {
        Node<int> *it = q.front();
        if (prev != NULL)
            prev->next = it;
        q.pop();

        while (it != NULL)
        {
            if (it->next == NULL)
                prev = it;
            if (it->child)
            {
                q.push(it->child);
                it->child = NULL;
            }
            it = it->next;
        }
    }

    return head;
}