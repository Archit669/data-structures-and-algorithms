#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *list1 = l1;
        ListNode *list2 = l2;
        ListNode *list3 = new ListNode(-1);
        ListNode *temp = list3;
        int carry = 0;

        while (list1 != NULL && list2 != NULL)
        {
            int sum = list1->val + list2->val + carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
            list1 = list1->next;
            list2 = list2->next;
        }

        while (list1 != NULL)
        {
            int sum = list1->val + carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
            list1 = list1->next;
        }

        while (list2 != NULL)
        {
            int sum = list2->val + carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
            list2 = list2->next;
        }

        if (carry)
        {
            temp->next = new ListNode(carry);
        }

        list3 = list3->next;
        return list3;
    }
};