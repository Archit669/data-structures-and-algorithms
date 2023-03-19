bool solve(Node* root, int min , int max){
    if (!root) return false;
    if (min == max) return true;
    bool left = solve(root->left, min, root->data -1); 
    if (left) return left;
    bool right = solve(root->right, root->data + 1, max); 
    return left || right;
}

bool isDeadEnd(Node *root)
{
    return solve(root, 1, INT_MAX);
}