#include <bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        vector<Node*> children;
};

// expectation -> 10 will print itself and its family
// d(20), d(30), d(40) will print themselves and their families
// d(10) = s(10) + d(20) + d(30) + d(40)
void display(Node* node){
    string str = to_string(node->data) + " -> ";
    for (auto &child : node->children){
        str+= to_string(child->data) + ", ";
    }
    str += ".";
    cout << str << endl;

    for (auto &child : node->children){
        display(child);
    }
}

int main(){
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110, -1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1,-1};
    Node* root = nullptr;
    stack<Node*> st;
    for (int i = 0 ; i < arr.size(); i++){
        if (arr[i] == -1){
            st.pop();
        }else{
            Node* newNode = new Node;
            newNode->data = arr[i];

            if (st.size() > 0){
                st.top()->children.push_back(newNode);
                st.push(newNode);
            }else{
                root = newNode;
                st.push(newNode);
            }
        }
    }

    display(root);
    return 0;
}