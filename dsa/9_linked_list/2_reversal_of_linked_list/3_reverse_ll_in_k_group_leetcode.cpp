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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) { 
        
        // base case
        if(head==NULL){
            return NULL;
        }
        
        // check given linked list size is greater than k or not
        int size = 1;
        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            size++;
        }
        if (size < k){
            return head;
        }
        
        // reverse linked list in k groups
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* frwd=NULL;
        int count=0;
        
        while(curr!=NULL && count<k && size >= k ){
            frwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=frwd;
            count++;
        }
        
        // recursive call (reverse first group else recusion will handle)
        if(curr!=NULL){
            // connect first reverse grp to other groups
            head->next= reverseKGroup(curr,k);
        }
        
        // return new head of linked list
        return prev;     
    }
};