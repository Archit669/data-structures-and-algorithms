#include <bits/stdc++.h>
using namespace std;

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

    ListNode *mergeTwoLists(ListNode *first, ListNode *second)
    {
        // create a dummy node
        ListNode *dummy = new ListNode(-1);

        // create tail of dummy node
        ListNode *dummyTail = dummy;

        // while first and second are not null
        while (first != NULL && second != NULL)
        {

            // if first element is less than or equal to second element
            if (first->val <= second->val)
            {
                dummyTail->next = first;
                first = first->next;
            }
            // if second element is less than first element
            else
            {
                dummyTail->next = second;
                second = second->next;
            }

            // move tail of dummy linked list
            dummyTail = dummyTail->next;
            dummyTail->next = NULL;
        }

        // if first linked list has element than connect it to dummy linked list
        if (first)
        {
            dummyTail->next = first;
        }
        // if second linked list has element than connect it to dummy linked list
        else
        {
            dummyTail->next = second;
        }

        // return ans
        return dummy->next;
    }

    ListNode *merge(vector<ListNode *> &lists, int start, int end)
    {
        if (start >= end)
        {
            return lists[start];
        }

        int mid = start + (end - start) / 2;

        ListNode *l1 = merge(lists, start, mid);
        ListNode *l2 = merge(lists, mid + 1, end);

        return mergeTwoLists(l1, l2);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        return merge(lists, 0, lists.size() - 1);
    }
};