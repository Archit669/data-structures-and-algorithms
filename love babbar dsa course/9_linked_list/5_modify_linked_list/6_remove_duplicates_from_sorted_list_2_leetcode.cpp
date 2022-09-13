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

/*

// iterative solution
// time complexity - O(N)
// space complexity - O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* dummyTail = dummy;
        
        ListNode* it = head;
        while (it != NULL){
            if (it->next == NULL || it->val != it->next->val){
                dummyTail->next = it;
                dummyTail = dummyTail ->next;
                it = it->next;
                dummyTail->next = NULL;
            }else{
                int data = it->val;
                while (it!= NULL && it->val == data){
                    it = it->next;
                }
            }
        }
        
        return dummy->next;
    }
};

*/


// recursive solution
// time complexity - O(N)
// space compelxity - O(N)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // base case 
        if (head == NULL || head ->next == NULL) return head;
        
        int val = head->val;
        
        if (val != head->next->val){
            head->next = deleteDuplicates(head->next);
            return head;
        }else{
            while (head != NULL && head->val == val){
                head = head->next;
            }
            
            return deleteDuplicates(head);
        }
        
        return NULL;
    }
};

