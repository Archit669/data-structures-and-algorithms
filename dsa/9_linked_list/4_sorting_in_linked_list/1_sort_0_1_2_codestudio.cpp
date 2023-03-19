#include <bits/stdc++.h>
using namespace std;


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





// Node* sortList(Node *head)
// {
//     // Write your code here.
//     int count0;
//     int count1;
//     int count2;
//     Node* temp= head;
//     while(temp!=NULL){
//         if(temp->data==0){
//             count0++;
//         }
//         else if(temp->data==1){
//             count1++;
//         }
//         else{
//             count2++;
//         }
//         temp=temp->next;
//     }
//     temp=head;
//     while(count0>0){
//         temp->data=0;
//         temp=temp->next;
//         count0--;
//     }
//     while(count1>0){
//         temp->data=1;
//         temp=temp->next;
//         count1--;
//     }
//     while(count2>0){
//         temp->data=2;
//         temp=temp->next;
//         count2--;
//     }
//     return head;
// }


// approach -2 using dummy node

Node* sortList(Node *head)
{
    Node* dummy0 = new Node(-1);
    Node* dummy1 = new Node(-1);
    Node* dummy2 = new Node(-1);
    
    Node* dummy0Tail = dummy0;
    Node* dummy1Tail = dummy1;
    Node* dummy2Tail = dummy2;
    
    while(head){
        if (head->data == 0) 
        {
            dummy0Tail->next = head; 
            dummy0Tail = dummy0Tail->next;         
        }
        if (head->data == 1) 
        {
            dummy1Tail->next = head; 
            dummy1Tail = dummy1Tail->next;        
        }
        if (head->data == 2) 
        {
            dummy2Tail->next = head; 
            dummy2Tail = dummy2Tail->next;       
        }
        
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
    }
    
    
    dummy1 = dummy1->next;
    dummy2 = dummy2->next;
    
    dummy0Tail->next = dummy1;
    dummy1Tail->next = dummy2;
    dummy0 = dummy0->next;
    
    return dummy0;
}
