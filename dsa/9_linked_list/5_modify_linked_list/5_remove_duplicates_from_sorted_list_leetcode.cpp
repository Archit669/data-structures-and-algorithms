#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 *
 */

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *it = head;
        while (it->next != NULL)
        {
            while (it->next != NULL && it->val == it->next->val)
            {
                it->next = it->next->next;
            }
            if (it->next == NULL)
                return head;
            it = it->next;
        }

        return head;
    }
};