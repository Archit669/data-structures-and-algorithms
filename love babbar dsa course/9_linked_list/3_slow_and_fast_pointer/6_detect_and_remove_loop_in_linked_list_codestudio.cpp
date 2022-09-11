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

bool detectAndRemoveCycle(Node *head)
{
    // if linked list is empty or has only element
    if (head == NULL || head->next == NULL)
        return 0;

    // create slow and fast pointer
    Node *slow = head;
    Node *fast = head;

    // move pointer until they meet if there is cycle 
    // and if fast reaches NULL then return 0
    do
    {
        // move slow and fast
        slow = slow->next;
        fast = fast->next;
        
        // if fast reaches null or not
        if (fast != NULL && fast->next != NULL)
        {
            fast = fast->next;
        }
        else
        {
            return 0;
        }

    } while (slow != fast);

    // find where cycle begins
    fast = head;
    Node *prev = NULL;

    // cycle begins where slow and fast meet
    while (slow != fast)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // if prev remains NULL then head is the node where cycle begins
    if (prev != NULL)
        prev->next = NULL;
    else
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        
        fast->next = NULL;
    }

    return 1;
}
