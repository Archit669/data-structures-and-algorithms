#include <bits/stdc++.h>
using namespace std;


// define node class
class Node
{
    public:

    // describe properties
    int data;
    Node *next;


    // create constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // create destructor (will delete entire linked list)
    ~Node()
    {   
        if (next != NULL)
        {
            delete next;
        }
    }
};


// define class linked-list
class LinkedList
{
    public:

    // create members
    Node* head;
    Node* tail;
    int size;
    
    // create constructor
    LinkedList(int data){
        head = new Node(data);
        tail = head;
        size = 1;
    }

    // creata destructor
    ~LinkedList()
    {
        delete head;
    }

    // methods for linked list


    // insert at head of linked list
    void InsertAtHead(int data)
    {
        Node* tmp = new Node(data);
        tmp->next = head;
        head = tmp;
        size++;
    }

    // insert at tail of linked list
    void InsertAtTail(int data)
    {
        Node* tmp = new Node(data);
        tail->next = tmp;
        tail = tmp;
        size++;
    }

    // insert in middle of linked list
    bool InsertAtMiddle(int data, int index){
        // if element has to insert at first position
        if (index ==0){
            InsertAtHead(data);
            return 1;
        }

        // if element has to insert at last
        if (index == size){
            InsertAtTail(data);
            return 1;
        }

        // if element have to insert at middle

        // if index > size or index < 0 so it is invlid and return 0
        if (index >= size || index < 0) return 0;

        // create a node tmp
        Node*tmp = new Node(data);

        // create a counter with point head
        Node*counter = head;
        int count = 0;

        // go to element before index where element has to inserted
        while (counter->next != NULL && count < index-1){
            counter = counter->next;
            count++;
        }

        // insert element at given index.
        tmp->next = counter->next;
        counter->next = tmp;

        // increment size of linked list.
        size++;

        // return 1 for success
        return 1;
    }

    // deletion of linked list
    bool DeleteAtMiddle(int index){
        // if first element has to be deleted
        if (index == 0){
            Node*tmp = head;
            head = head->next;
            tmp->next = NULL;
            delete tmp;
            size--;
            return 1;
        }

        // for check of valid index
        if (index < 0 && index >= size) return 0;
        
        // for element in middle 
        Node* prev = NULL;
        Node* curr = head;
        int count = 0;

        // set curr to element which has to be deleted
        while (count<index){
            prev = curr;
            curr = curr->next;
            count++;
        }
        
        // for last element
        if (curr == NULL){
            prev->next = NULL;
            delete curr;
            size--;
            return 1;
        }

        // delete middle element
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        size--;

        return 1; 
    }

    // searching in linked list
    int search(int data){
        Node*temp = head;
        int index = 0;
        while(temp->next != NULL){
            if (temp->data == data){
                return index;
                break;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    // display linked list
    void display()
    {
        Node* tmp = head;
        while (tmp!=NULL){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }cout <<endl;
    }

};

int main()
{
    LinkedList* l1 =  new LinkedList(5);
    l1->InsertAtHead(10);
    l1->InsertAtHead(9);
    l1->display();
    delete l1;
    return 0;
}