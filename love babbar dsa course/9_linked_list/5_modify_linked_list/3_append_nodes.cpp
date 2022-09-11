#include <bits/stdc++.h>
using namespace std;

/****************************************************************
    Following is the class structure of the Node class:
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

Node *addNodes(Node *head, int n, int m)
{
    Node *temp = head;

    while (temp != NULL)
    {
        int count = 1;
        while (temp != NULL && count <= m)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL)
            return head;

        count = 1;
        int val = 0;

        while (temp->next != NULL && count < n)
        {
            val += temp->data;
            temp = temp->next;
            count++;
        }

        val += temp->data;
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        temp = temp->next->next;
    }

    return head;
}