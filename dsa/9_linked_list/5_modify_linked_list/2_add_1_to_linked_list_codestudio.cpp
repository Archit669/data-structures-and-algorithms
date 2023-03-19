#include <bits/stdc++.h>
using namespace std;

/****************************************************************

    Following is the class structure of the Node class;

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

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *list1 = l1;
    Node *list2 = l2;
    Node *list3 = new Node(-1);
    Node *temp = list3;
    int carry = 0;

    while (list1 != NULL && list2 != NULL)
    {
        int sum = list1->data + list2->data + carry;
        temp->next = new Node(sum % 10);
        carry = sum / 10;
        temp = temp->next;
        list1 = list1->next;
        list2 = list2->next;
    }

    while (list1 != NULL)
    {
        int sum = list1->data + carry;
        temp->next = new Node(sum % 10);
        carry = sum / 10;
        temp = temp->next;
        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        int sum = list2->data + carry;
        temp->next = new Node(sum % 10);
        carry = sum / 10;
        temp = temp->next;
        list2 = list2->next;
    }

    if (carry)
    {
        temp->next = new Node(carry);
    }

    list3 = list3->next;
    return list3;
}

Node *addTwoLists(Node *first, Node *second)
{
    while (first != NULL && first->data == 0)
        first = first->next;
    if (first == NULL)
        return second;
    Node *ans = addTwoNumbers(reverse(first), reverse(second));
    ans = reverse(ans);
    return ans;
}

Node *addOne(Node *head)
{
    return addTwoLists(head, new Node(1));
}
