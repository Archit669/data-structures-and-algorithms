#include <bits/stdc++.h>
using namespace std;

/****************************************************************
    Following is the class structure of the Node class:

*****************************************************************/

class Node
{
public:
    char data;
    Node *next;
    Node *random;
    Node(char data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

bool isItAccepted(Node *head, string &str)
{
    // create an iterator
    Node *it = head;

    // find where first character of string start in linked list
    while (it != NULL && it->data != str[0])
    {
        it = it->next;
    }

    // if it == Null then string is not acceptable by  state diagram
    if (it == NULL)
        return false;

    // if it != NULL

    for (int i = 1; i < str.size(); i++)
    {
        int val = str[i];
        // check if value present at next pointer
        if (it->next != NULL && it->next->data == val)
        {
            it = it->next;
        }
        // check if value present at random pointer
        else if (it->random != NULL && it->random->data == val)
        {
            it = it->random;
        }
        // string cannot be accepted by state diagram
        else
        {
            return false;
        }
    }

    // string completely complete
    if (it->next == NULL)
        return true;

    return false;
}