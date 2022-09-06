#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

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

Node<int> *middleOfLinkedList(Node<int> *head)
{
    Node<int> *slow = head;
    Node<int> *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node<int> *reverse(Node<int> *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node<int> *newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

Node<int> *rearrangeList(Node<int> *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node<int> *middle = middleOfLinkedList(head);
    Node<int> *l1 = head;
    Node<int> *l2 = middle->next;
    l2 = reverse(l2);
    middle->next = NULL;

    Node<int> *dummy = new Node<int>(-1);
    Node<int> *insertor = dummy;

    bool toggle = 0;

    while (l1 != NULL && l2 != NULL)
    {
        if (toggle == 0)
        {
            insertor->next = l1;
            l1 = l1->next;
        }
        else
        {
            insertor->next = l2;
            l2 = l2->next;
        }

        insertor = insertor->next;
        insertor->next = NULL;
        toggle = !toggle;
    }

    insertor->next = l1;

    dummy = dummy->next;
    return dummy;
}