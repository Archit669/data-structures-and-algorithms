#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // if linked list has only node
        if (head == NULL || head->next == NULL)
            return head;

        // declare curr, prev and forward to reverse given part of linked list
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *forward = NULL;

        // declare variable for tail of linked list before group so that we can attach it later to reveresed part.
        ListNode *tailOfLinkedListBeforeGroup = NULL;

        // move curr to start of part which has to reverse
        int count = 1;

        while (count < left)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        // assign value to tail of linked list before group
        tailOfLinkedListBeforeGroup = prev;

        // declare variable to keep track of head of part of linked list
        ListNode *groupLinkedListHead = curr;

        // count no of nodes
        int nodes = right - left + 1;

        // reverse part of linked list
        count = 1;

        while (count <= nodes)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        // attach newHead of reversed part to left linked list tail
        if (left != 1)
            tailOfLinkedListBeforeGroup->next = prev;

        // attach here head is part of reversed part so update head as newHead
        if (left == 1)
            head = prev;

        // attach reversed part to remaining linked list after it
        groupLinkedListHead->next = curr;

        // return head of final output
        return head;
    }
};