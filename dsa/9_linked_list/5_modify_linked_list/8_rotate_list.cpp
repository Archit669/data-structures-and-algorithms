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

class Solution {
    
    ListNode* reverseFirstKNodes(ListNode* head, int k){
        if (head == NULL || head->next == NULL || k < 1) return head;
        int count = 1;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while (head != NULL && count <= k){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        
        head->next = curr;
        return prev;
    }
   
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k < 1) return head;
        int n = 0;
        ListNode* temp = head;
        while (temp != NULL){
            temp = temp ->next;
            n++;
        }  
        k = k%n;  
        head = reverseFirstKNodes(head,n-k);
        head = reverseFirstKNodes(head,n);
        head = reverseFirstKNodes(head,k);
        
        return head;
    }
};