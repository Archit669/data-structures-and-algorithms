#include <bits/stdc++.h>
using namespace std;

// without using stl

class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value){
            this->key = key;
            this->value = value;
            this->prev = NULL;
            this->next = NULL;
        }
};


class LRUCache {
    Node* head, *tail;
    int capacity;
    unordered_map<int,Node* > m;

public:
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end() ) return -1;
        Node* temp = m[key];
        // remove from curr position
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        // put it just after head
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
        return m[key]->value;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()){
            Node* temp = m[key];
            // remove from curr position
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            // put it just after head
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            temp->prev = head;
            // update value
            temp->value = value;
        }
        else{
            if (m.size() == capacity){
                // remove least used guy
                Node* temp = tail-> prev;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = NULL;
                temp->prev = NULL;
                m.erase(temp->key);
                delete temp;
            }

            Node* temp = new Node(key,value);
            // put it just after head
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            temp->prev = head;
            // map it 
            m[key] = temp;

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// using stl
class LRUCache {
    list<pair<int,int>> l;
    int capacity;
    unordered_map<int, list< pair<int,int>>::iterator > m;

public:
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end() ) return -1;
        l.splice(l.begin(),l, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()){
            l.splice(l.begin(),l, m[key]);
            // update value
            l.begin()->second = value;
        }
        else{
            if (m.size() == capacity){
                // remove least used guy
                int d_key = l.back().first;
                l.pop_back();
                m.erase(d_key);
            }

            // put it at head
            l.push_front({key,value});
            
            // map it 
            m[key] = l.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */