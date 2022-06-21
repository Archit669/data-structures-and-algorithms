#include <bits/stdc++.h>
using namespace std;

// create class node for doubly linked list
class Node
{
    public:
        // data members

        // create int which store data
        int data;

        // create pointer which will point to next node
        Node* next;

        // create pointer which will point to prev node
        Node* prev;


        // create a constructor which will create a node for doubly linked list
        Node()
        {
            // assign values to data members
            this->data = 0;
            this->next = NULL;
            this->prev = NULL;
        }

        // create a another paramaterized constructor which will create a node for doubly linked list with desired data
        Node(int data)
        {
            // assign values to data members;
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        // create destructor
        ~Node()
        {   
            // delete node till it's next is not null;
            if (next!=NULL)
            {
                delete next;
            }

        }
};


// create a class doubly linked list
class doublyLinkedList
{
    public:
        // data members

        // create head for doubly linked list
        Node* head;

        // create tail for doubly linked list
        Node* tail;

        // create size which will store size for doubly linked list
        int size;

        // constructor

        // create a constructor without any parameter
        doublyLinkedList(){
            this->head = new Node;
            this->tail = head;
            this->size = 1;
        }

        // create a paramatrized constructor
        doublyLinkedList(int data){
            this->head = new Node(data);
            this->tail = head;
            this-> size = 1;
        }


        // destuctor

        // create a destructor 
        ~doublyLinkedList()
        {
            delete head;
        }


        // methods for doubly linked list

        // method for insert a node at head
        void InsertAtHead(int data)
        {
            // create a new node which has to attach at head
            Node* temp = new Node(data);

            // now point next of temp to current head
            temp->next = head;

            // connect prev of head to temp;
            head->prev = temp;

            // assign temp as new head
            head = temp;

            //increment size of linked list
            size++;

        }

        // method for insert a node at tail
        void InsertAtTail(int data)
        {
            // create a new node which has to attach at tail
            Node* temp = new Node(data);

            // now point next of tail to temp
            tail->next = temp;

            // now point prev of temp to tail
            temp->prev = tail;

            // assign temp as new tail
            tail = temp;

            //increment size of linked list
            size++;
        }

        // method for insert a node at middle
        int InsertAtMiddle(int data, int index)
        {

            // if index == 0
            if (index == 0)
            {
                InsertAtHead(data);
                return 1;
            }

            // if index == size
            if (index == size)
            {
                InsertAtTail(data);
                return 1;
            }

            // insert at index other than 0 and size
            if (index<0 || index>size) return 0;

            // create a new node which has to attach at middle
            Node* temp = new Node(data);

            // go to index-1 to place node at index
            int idx = 0;
            Node* insertor = head;

            // it will break when idx == index-1
            while (idx < index-1)
            {
                insertor = insertor->next;
                idx++;
            }

            // attach node next to node where insertor is pointing
            
            // point temp of next to insertor of next
            temp->next = insertor->next;

            // point temp of prev to insertor
            temp->prev = insertor;

            // point insertor of next of prev to temp
            insertor->next->prev = temp;

            // point insertor of next to temp;
            insertor->next = temp;

            // increment size of linked list
            size++;

            return 1;
        }


        // deleting in doubly linked list
        int DeleteAtMiddle(int index){
            // delete head
            if (index == 0)
            {   
                Node* temp = head;
                // make head of prev null
                head->prev = NULL;

                // make head of next of prev null
                head->next->prev = NULL;

                // assign new head as head of next
                head = head->next;

                // make temp (previous head) of next as null
                temp->next = NULL;

                // delete temp
                delete temp;

                // decrement size of linked list
                size--;
                
                return 1;
            }

            // if (index == size-1)
            if (index == size-1)
            {
                Node* temp = tail;
                
                
                // make new tail
                tail = tail->prev;
                // make next of tail as null
                tail->next = NULL;
                // make temp of prev as null
                temp->prev = NULL;
                // make temp of next as null
                temp->next = NULL;
                // delete temp
                delete temp;
                // decrement size of linked list
                size--;

                return 1;
            }

            // condition for edge case
            if (index < 0 && index>=size)
            {
                return 0;
            }

            // delte in middle
            Node* deletor = head;
            Node* detacher = NULL;

            // go to node which index is specified
            int idx = 0;
            while (idx < index)
            {
                detacher = deletor;
                deletor = deletor->next;
                idx++;
            }

            // delete node

            // make connection of before and after node of given index
            detacher->next = deletor->next;
            deletor->next->prev = detacher;

            // cut connection of node at given index
            deletor->prev = NULL;
            deletor->next = NULL;

            // delete node at index specified
            delete deletor;

            // decrement the size 
            size--;

            // return 1 as operation successful
            return 1;
        }


        // method to search in doubly linked list
        int search(int data)
        {
            // create pointer to traverse node
            Node* trav = head;

            // create idx to store index
            int idx = 0;

            // traversal of doubly linked list
            while(trav!=NULL)
            {
                if (trav->data == data)
                {
                    return idx;
                }
                trav = trav->next;
                idx++;
            }

            // -1 for not found
            return -1;
        }


        // method to display doubly linked list
        void display(){
            // create a temp pointer to traverse linked list
            Node* temp = head;
            // it will stop when it reaches last element 
            while(temp != NULL)
            { 
                // print data of linked list
                cout << temp->data << " ";

                // increment temp;
                temp = temp->next;

            }cout << endl;
        }
};
 
int main(){
    doublyLinkedList l1(3);
    l1.display();
    
    return 0;
}