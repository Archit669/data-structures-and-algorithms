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

int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *ptr1 = firstHead;
    Node *ptr2 = secondHead;

    while (ptr1 && ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if (ptr1 == ptr2)
            return ptr1->data;
    }

    int count1 = 0;
    int count2 = 0;
    while (ptr1 || ptr2)
    {
        if (ptr1)
        {
            ptr1 = ptr1->next;
            count1++;
        }
        else
        {
            ptr2 = ptr2->next;
            count2++;
        }
    }

    ptr1 = firstHead;
    ptr2 = secondHead;

    while (count1--)
    {
        ptr1 = ptr1->next;
    }

    while (count2--)
    {
        ptr2 = ptr2->next;
    }

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if (ptr1 == NULL || ptr2 == NULL)
            return -1;
    }

    return ptr1->data;
}