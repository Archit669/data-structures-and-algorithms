// dfs approach

class Solution {
    void dfs(Node* root){
        if (!root) return;
        dfs(root->left);
        dfs(root->right);
        Node *left = root->left;
        Node *right = root->right;
        while (left){
            left->next = right;
            left = left->right, right = right->left;
        }
    }

public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};


// bfs appraoch
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> que;
        que.push(root);

        while (!que.empty()){
            int size = que.size();
            
            for (int idx = 0 ; idx < size ; idx++){
                Node* front = que.front();
                que.pop();

                if (idx != size-1){
                    front->next = que.front();
                }
                if (front->left)
                    que.push(front->left);
                    
                if (front->right)
                    que.push(front->right);
            }
        }

        return root;
    }
};