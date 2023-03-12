// bfs approach

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

// dfs approach

class Solution {
    Node* helper(Node* root){
        if (!root) return nullptr;
        if (root->left) return root->left;
        if (root->right) return root->right;
        return helper(root->next);
    }
    
    void dfs(Node* root){
        if (!root) return ;
        if (root->left) root->left->next = root->right? root->right : helper(root->next);
        if (root->right) root->right->next = helper(root->next);
        dfs(root->right); dfs(root->left);
    }
public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};