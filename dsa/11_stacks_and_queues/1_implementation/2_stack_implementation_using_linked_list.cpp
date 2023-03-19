#include <bits/stdc++.h>
using namespace std;


// Following is the class structure of the Node class:

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

class Stack
{
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        return false;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        if (top == NULL)
            top = temp;
        else
        {
            temp->next = top;
            top = temp;
        }
        size++;
    }

    void pop()
    {
        if (top == NULL)
            return;
        Node *temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    int getTop()
    {
        if (top != NULL)
            return top->data;
        return -1;
    }
};