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

// // time complexity - O(N^2)
// // space complexity - O(1)

// long long int calculateInversionCnt(Node *head){
// 	Node* temp = head;
//     long long count = 0;
//     while(temp != NULL){
//         Node* temp2 = temp->next;
//         while (temp2 != NULL){
//             if (temp->data > temp2->data){
//                 count++;
//             }
//             temp2 = temp2->next;
//         }
//         temp = temp ->next;
//     }
//     return count;
// }


// time complexity - O(nlogn)
// space complexity - O(n)

Node *middleOfLinkedList(Node* head, long long int&left_size){
    Node* slow = head;
    Node* fast = head->next;
    
    left_size = 1;
    
    while (fast!= NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow= slow->next;
        left_size++;
    }
    
   return slow;
}

Node *sortTwoLists(Node *first, Node *second , long long int &left_size , long long int &inv_count)
{
    // edge cases
    if (first == NULL) return second;
    if (second == NULL) return first;
    
    // create a dummy node
    Node *dummy = new Node(-1);

    // create tail of dummy node
    Node *dummyTail = dummy;
    
    int curPositionInLeftList = 0;

    // while first and second are not null
    while (first != NULL && second != NULL)
    {

        // if first element is less than or equal to second element
        if (first->data <= second->data)
        {
            dummyTail->next = first;
            first = first->next;
            curPositionInLeftList++;
        }
        // if second element is less than first element
        else
        {
            dummyTail->next = second;
            second = second->next;
            inv_count+= left_size - curPositionInLeftList;
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


Node *sortLL(Node *head, long long int &inv_count)
{
    // base case
    if (head == NULL || head->next == NULL) return head;
    
    long long left_size = 0;
    
    Node* mid = middleOfLinkedList(head, left_size);
    
    
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    
    left = sortLL(left,inv_count);
    right = sortLL(right,inv_count);
    
    head = sortTwoLists(left,right, left_size,inv_count);
    
    return head;
}


long long int calculateInversionCnt(Node *head){
	long long inv_count = 0;
    sortLL(head,inv_count);
    return inv_count;
}