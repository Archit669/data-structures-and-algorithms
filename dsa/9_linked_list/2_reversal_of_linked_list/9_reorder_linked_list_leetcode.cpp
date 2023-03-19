#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode *middleOfLinkedList(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode *rearrangeList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *middle = middleOfLinkedList(head);
        ListNode *l1 = head;
        ListNode *l2 = middle->next;
        l2 = reverse(l2);
        middle->next = NULL;

        ListNode *dummy = new ListNode(-1);
        ListNode *insertor = dummy;

        bool toggle = 0;

        while (l1 != NULL && l2 != NULL)
        {
            if (toggle == 0)
            {
                insertor->next = l1;
                l1 = l1->next;
            }
            else
            {
                insertor->next = l2;
                l2 = l2->next;
            }

            insertor = insertor->next;
            insertor->next = NULL;
            toggle = !toggle;
        }

        insertor->next = l1;

        dummy = dummy->next;
        return dummy;
    }

    void reorderList(ListNode *head)
    {
        head = rearrangeList(head);
    }
};