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

Node *segregateOddEven(Node *head)
{
    Node *dummyodd = new Node(-1);
    Node *dummyeven = new Node(-1);

    Node *dummyoddTail = dummyodd;
    Node *dummyevenTail = dummyeven;

    while (head != NULL)
    {
        if (head->data & 1)
        {
            dummyoddTail->next = head;
            head = head->next;
            dummyoddTail = dummyoddTail->next;
            dummyoddTail->next = NULL;
        }
        else
        {
            dummyevenTail->next = head;
            head = head->next;
            dummyevenTail = dummyevenTail->next;
            dummyevenTail->next = NULL;
        }
    }

    dummyoddTail->next = dummyeven->next;
    dummyodd = dummyodd->next;
    return dummyodd;
}
