#include <bits/stdc++.h>
using namespace std;

/*************************************************************

    Following is the class structure of the Node class:

************************************************************/

class Node
{
public:
    int x, y;
    Node *next;
    Node(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->next = NULL;
    }
};

Node *connectMidPoints(Node *head)
{
    Node *ans = new Node(-1, -1);
    Node *ansTail = ans;
    Node *cor1 = head;

    while (cor1 != NULL && cor1->next != NULL)
    {
        Node *cor2 = cor1->next;
        if (cor1->x == cor2->x)
        {
            while (cor2->next && cor2->next->x == cor1->x)
            {
                cor2 = cor2->next;
            }
        }
        else
        {
            while (cor2->next && cor2->next->y == cor1->y)
            {
                cor2 = cor2->next;
            }
        }

        int midx = (cor1->x + cor2->x) / 2;
        int midy = (cor1->y + cor2->y) / 2;
        ansTail->next = new Node(midx, midy);
        ansTail = ansTail->next;

        cor1 = cor2;
    }
    return ans->next;
}
