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

Node *solve(Node *head, Node *dummy, unordered_map<int, int> &m)
{
    if (head == NULL)
        return dummy;
    Node *newtail = solve(head->next, dummy, m);
    if (m.find(head->data) == m.end())
    {
        m[head->data]++;
        newtail->next = new Node(head->data);
        newtail = newtail->next;
    }

    return newtail;
}

Node *lastAppearance(Node *head)
{
    unordered_map<int, int> m;
    Node *dummy = new Node(-1);
    solve(head, dummy, m);
    dummy = dummy->next;
    dummy = reverse(dummy);
    return dummy;
}