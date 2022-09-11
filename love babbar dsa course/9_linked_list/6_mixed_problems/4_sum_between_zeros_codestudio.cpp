#include <bits/stdc++.h>
using namespace std;

/****************************************************************
    Following is the class structure of the Node class:
*****************************************************************/

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


Node* sumBetweenZeroes(Node* head) 
{
    Node* dummy = new Node(-1);
    Node* dummyTail = dummy;
    
    int sum = 0;
    bool flag = 1;
    
    while (head != NULL){
       if (head ->data ==0) flag = !flag;
       if (flag == 0){
           sum+= head->data;
       }else{
           dummyTail->next = new Node(sum);
           dummyTail = dummyTail->next;
           dummyTail->next = NULL;
           flag = !flag;
           sum = 0;
       }
        
        head = head->next;
    }
    
    return dummy->next;
}