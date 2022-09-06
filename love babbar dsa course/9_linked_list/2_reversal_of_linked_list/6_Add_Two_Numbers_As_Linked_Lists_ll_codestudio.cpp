#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the linked list node structure:

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };

************************************************************/

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }
};

Node<int> *reverse(Node<int> *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node<int> *newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

Node<int> *addTwoNumbers(Node<int> *l1, Node<int> *l2)
{
    Node<int> *list1 = l1;
    Node<int> *list2 = l2;
    Node<int> *list3 = new Node<int>(-1);
    Node<int> *temp = list3;
    int carry = 0;

    while (list1 != NULL && list2 != NULL)
    {
        int sum = list1->data + list2->data + carry;
        temp->next = new Node<int>(sum % 10);
        carry = sum / 10;
        temp = temp->next;
        list1 = list1->next;
        list2 = list2->next;
    }

    while (list1 != NULL)
    {
        int sum = list1->data + carry;
        temp->next = new Node<int>(sum % 10);
        carry = sum / 10;
        temp = temp->next;
        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        int sum = list2->data + carry;
        temp->next = new Node<int>(sum % 10);
        carry = sum / 10;
        temp = temp->next;
        list2 = list2->next;
    }

    if (carry)
    {
        temp->next = new Node<int>(carry);
    }

    list3 = list3->next;
    return list3;
}

Node<int> *addTwoLists(Node<int> *first, Node<int> *second)
{
    Node<int> *ans = addTwoNumbers(reverse(first), reverse(second));
    ans = reverse(ans);
    return ans;
}