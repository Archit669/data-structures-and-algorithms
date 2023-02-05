//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function

bool findPath(Node* root, int k , int node, vector<int> &path){
    if (root == NULL) return false;
    if (root->data == node){
        path.push_back(root->data);
        return true;
    }
    if (findPath(root->left, k , node, path)){
        path.push_back(root->data);
        return true;
    }
    if (findPath(root->right, k , node, path)){
        path.push_back(root->data);
        return true;
    }
    
    return false;
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    int count = -1;
    if (findPath(root, k, node, path))
    {
        for (auto &x : path){
            count++;
            if (count == k) return x;
        }
    }
    
    return -1;
}


// approach-2

Node* solve(Node* root, int &k , int node){
    if (root == NULL) return NULL;
    if (root->data == node) return root;
    
    Node* leftAns = solve(root->left, k , node);
    Node* rightAns = solve(root->right, k , node);
    
    if (leftAns && !rightAns){
        k--;
        if (k <= 0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if (!leftAns && rightAns){
        k--;
        if (k <= 0){
            k = INT_MAX;
            return root;
        }
        
        return rightAns;
        
    }
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k , node);
    if (ans == NULL || ans->data == node) return -1;
    return ans->data;
}

