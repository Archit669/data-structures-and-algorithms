// { Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:

    //Function to reverse a linked list.(bruteforce recursively)
    // time complexity - O(n^2)
    // space complexity - O(n)
    struct Node* reverseList(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        
        
        struct Node* new_head = reverseList(head->next);
        struct Node* temp = new_head;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = head;
        head->next = NULL;
        
        return new_head;
        
    }
    //Function to reverse a linked list.(recursively)
    // time complexity - O(N)
    // space complexity - O(N)
    struct Node* reverseList(struct Node *head)
    {
        // base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        
        // recursive case
        struct Node* new_head = reverseList(head->next);
        
        // connect new reversed linked list to head
        head->next->next = head;
        head->next = NULL;
        
        
        return new_head;
    
    }


    // function to reverse a linked list (iteratively)
    // three pointer approach
    // time complexity - O(N)
    // space complexity - O(1)
    struct Node* reverseList(struct Node *head)
    {
        struct Node* prev = NULL;
        struct Node* curr = head;
        
        while(curr!=NULL)
        {
            struct Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
    
};
    


// { Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}

  // } Driver Code Ends



// ####################### coding ninjas #################

  // using stack approach

//   #include <bits/stdc++.h> 
// /****************************************************************

//     Following is the class structure of the LinkedListNode class:

//     template <typename T>
//     class LinkedListNode
//     {
//     public:
//         T data;
//         LinkedListNode<T> *next;
//         LinkedListNode(T data)
//         {
//             this->data = data;
//             this->next = NULL;
//         }
//     };

// *****************************************************************/

// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
// { 
//     // if there no element or only one element in linked list
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }
    
//     // create a stack to push address of nodes of linked list
//     stack<LinkedListNode<int> *>  s;
    
//     // push all node address to stack
//     while(head != NULL)
//     {
//         s.push(head);
//         head = head->next;
//     }
    
//     // take top address as new head
//     LinkedListNode<int> *new_head = s.top();
    
//     // now take temp pointer 
//     LinkedListNode<int> *temp = new_head;
    
//     // pop new_head
//     s.pop();
    
    
//     // loop will execute till stack is empty
//     while(s.size())
//     {   
//         // if stack has only one node then it will connected to last second node and its next make null
//         if (s.size() == 1){
//             temp->next = s.top();
//             s.pop();
//             temp->next->next = NULL;
//         }
//         // otherwise connect top node to remaining node pop it and move to next node
//         else{
//             temp->next = s.top();
//             temp= temp->next;
//             s.pop();
//         }
//     }
    
//     // return new head
    
//     return new_head;
    
// }