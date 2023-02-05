//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    
    // // time complexity - O(N^2)
    // // space complexity - O(N)
    // // Function to return the diameter of a Binary Tree.
    // int height(Node* root){
    //     if (root == NULL) return 0;
    //     return 1+ max( height(root->left), height(root->right) );
    // }
    
    // int diameter(Node* root) {
    //     if (root == NULL) return 0;
    //     int opt1 = diameter(root->left);
    //     int opt2 = diameter(root->right);
    //     int opt3=  1+ height(root->left) + height(root->right);
    //     return max(opt1, max(opt2, opt3));
    // }


    // time complexity - O(N)
    // space complexity - O(N)
    // Function to return the diameter of a Binary Tree.
    pair<int,int> diameterFast(Node* root){
        if (root == NULL) return {0,0};
        pair<int,int> p1 = diameterFast(root->left);
        pair<int,int> p2 = diameterFast(root->right);
        int opt1 = p1.first;
        int opt2 = p2.first;
        int opt3=  1+ p1.second + p2.second;
        
        pair<int,int> ans = {max(opt1, max(opt2, opt3)) , 1 + max(p1.second, p2.second)};
        return ans;
    }
    
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}

// } Driver Code Ends