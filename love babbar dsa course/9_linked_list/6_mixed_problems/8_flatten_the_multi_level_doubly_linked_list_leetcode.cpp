#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
    Node* solve(Node* head , Node* &nex) {
        // create iterator to iterate linked list
        Node* it = head;
        
        // while it is not equal to null
        while (it != NULL){
             // find end of one level of linked list so update nex 
             if (it->next == NULL) nex = it;
            
             // if it has child
             if (it->child){
                 // create after to keep track of remaining linked list
                 Node* after = it->next;
                 
                 // attach it to flattened linked list of another level
                 it->next = solve(it->child, nex);
                 
                 // make child node to null
                 it->child = NULL;
                 
                 // update prev of it->next
                 it->next->prev = it;
                 
                 // now connect end of flattened linked list to after
                 nex->next = after;
                 
                 // update prev of after
                 if (after != NULL)
                    after->prev = nex;
                 
                 // update it 
                 it = nex;
             }
            
             it = it->next;
        }
        
        return head;
    }
    
public:
    Node* flatten(Node* head) {
        // create pointer nex initialized to NULL
        Node* nex = NULL;
        
        // return head of flattened doubly linked list
        return solve(head, nex);
    }
};