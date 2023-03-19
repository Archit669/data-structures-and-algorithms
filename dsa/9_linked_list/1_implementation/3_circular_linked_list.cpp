#include <bits/stdc++.h>
using namespace std;

// create a class node for circular linked list
class Node
{
    public: 
    // data members
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        if (next!=NULL)
        {
            delete next;
        }
    }
};

// creata a circular linked list class
class circularLinkedList
{
    public:
        // data members
        Node* head;
        Node* tail;
        int size;

        // constructor
        circularLinkedList(int data){
            head = new Node(data);
            tail = head;
            tail->next = head;
            size = 1;
        }

        // destructor
        ~circularLinkedList()
        {
            tail->next = NULL;
            delete head;
        }

        // methods for circular linked list
        
        // insert at head of linked list
        void InsertAtHead(int data)
        {
            // create a node which has to insert at head
            Node*temp = new Node(data);
            // point temp to head
            temp->next = head;
            // point tail to temp
            tail->next = temp;
            // make new head
            head = temp;
            // increment size of linked list
            size++;
        }


        // insert at tail of linked list
        void InsertAtTail(int data)
        {
            // create a node which has to insert at tail
            Node*temp = new Node(data);
            // point temp to tail
            temp->next = head;
            // point tail to temp
            tail->next = temp;
            // make new tail
            tail = temp;
            // increment size of linked list
            size++;
        }

        // insert at middle of linked list
        bool InsertAtMiddle(int data, int index)
        {
            // to keep index in range of linked list
            index = index % size;

            // for insert at head(index == 0)
            if (index == 0)
            {
                InsertAtHead(data);
                return 1;
            }


            // for insert at given index
            
            // go to index-1 to insert
            int idx = 0;
            Node* insertor = head;

            while (idx < index-1)
            {
                // move head forward
                insertor = insertor->next;
                idx++;
            }

            //insert at index

            // create a new node
            Node* temp = new Node(data);
            // now point temp to insertor of next
            temp->next = insertor->next;
            // now point insertor to temp
            insertor->next = temp;
            // increment size of linked list
            size++;

            // return 1 for success
            return 1;
        }


        // deletion in circular linked list
        void DeletionAtMiddle(int index)
        {
            // to keep index as valid index
            index = index%size;

            // delete first node
             if (index == 0)
             {
                Node* temp = head;
                head = head->next;
                temp->next = NULL;
                tail->next = head;
                delete temp;
                size--;
                return ;
             }

             // delete in middle

            Node* deletor = head;
            Node* prev = NULL;
            int idx = 0;

            // move deletor to index node
            while(idx < index){
                prev = deletor;
                deletor = deletor->next;
                idx++;
            }

             // delete last node
             if (index == size-1)
             {
                tail = prev;
                tail->next = head;
                deletor->next = NULL;
                delete deletor;
                size--;
                return ;
             }

             // delete in middle
             prev->next = deletor->next;
             deletor->next = NULL;
             delete deletor;
             size--;
        }


    // searching in linked list
    int search(int data){
        Node*temp = head;

        int index = 0;

        do{
            // temp find data
            if (temp->data == data)
            {
                // return index
                return index;
                break;
            }

            temp = temp->next;
            index++;

        // loop execute till it again reach to head
        }while(temp!=head);

        // element not found
        return -1;
    }

        // display circular linked list
        void display()
        {
            // create counter and temp node pointer for traversal
            int counter = size;
            Node* temp = head;

            // loop for traverse linked list
            while (counter)
            {
                // print data
                cout << temp->data << " ";
                // increment pointer
                temp = temp->next;
                // decrement size
                counter--;
            }cout << endl;
        }
};
 
int main(){
    circularLinkedList l1(5);
    l1.InsertAtTail(3);
    l1.InsertAtTail(3);
    l1.InsertAtMiddle(2,3);
    // l1.DeletionAtMiddle(3);
    l1.display();
    cout << l1.search(0) << endl;
    return 0;
}