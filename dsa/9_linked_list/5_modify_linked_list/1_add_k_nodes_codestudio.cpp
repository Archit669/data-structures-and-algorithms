#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:

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

Node *getListAfterAddingNodes(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int val = 0;
    Node *temp = head;
    int count = 1;

    while (temp != NULL)
    {
        while (count < k)
        {
            if (temp->next == NULL)
                break;
            val += temp->data;
            temp = temp->next;
            count++;
        }
        val += temp->data;

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        temp = temp->next->next;
        count = 1;
        val = 0;
    }

    return head;
}