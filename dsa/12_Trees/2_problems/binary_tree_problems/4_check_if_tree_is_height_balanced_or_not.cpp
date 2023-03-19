//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
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
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:

    // time complexity - O(N^2)
    // space complexity - O(h)
    int height(Node* root){
        if (root == NULL) return 0;
        return 1+ max(height(root->left), height(root->right));
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if (root == NULL) return true;
        
        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;

        int h1, h2;
        h1 = height(root->left); 
        h2 = height (root->right); 
        
        return abs(h1-h2) <=1;
    }

    // time complexity - O(N)
    // space complexity - O(h)
    pair<int,int> isBalancedFast(Node* root){
        if (root == NULL) return {true, 0};
        pair<int,int> p1 = isBalancedFast(root->left);
        pair<int,int> p2 = isBalancedFast(root->right);
        
        int h1, h2;
        h1 = p1.second; 
        h2 = p2.second;
        
        if (!p1.first) return {false, 1+ max(h1,h2)};
        if (!p2.first) return {false, 1+ max(h1,h2)};
        
        return {abs(h1-h2) <=1 , 1+ max(h1,h2)};
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
    
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends