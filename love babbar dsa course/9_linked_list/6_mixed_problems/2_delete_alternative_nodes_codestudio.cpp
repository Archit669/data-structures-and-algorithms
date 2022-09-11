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

void deleteAlternateNodes(Node *head)
{
    while (head != NULL && head->next != NULL)
    {
        head->next = head->next->next;
        head = head->next;
    }
}