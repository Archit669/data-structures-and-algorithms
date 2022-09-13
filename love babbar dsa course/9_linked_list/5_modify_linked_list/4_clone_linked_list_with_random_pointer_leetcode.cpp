#include <bits/stdc++.h>
using namespace std;
 
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* it = head;
          
        while (it){
            Node* temp = new Node(it->val);
            temp->next = it->next;
            it->next = temp;
            it = it->next->next;
        }
        
        it = head;
        while(it){
             if (it->random != NULL)
                it->next->random = it->random->next;
            
            it = it->next->next;
        }
        
        Node* dummy = new Node(-1);
        Node* dummyTail = dummy;
        it = head;
        
        while(it){
            dummyTail->next = it->next;
            it->next = it->next->next;
            dummyTail = dummyTail->next;
            it = it->next;
        }
        
        return dummy->next;

    }
};