#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Node
{
public:
    int data = 0;

    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }
};


Node *constructor01(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return NULL;
    }

    vector<Node *> stack;

    stack.push_back(new Node(arr[0]));

    Node *root = stack[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != -1)
        {
            Node *node = stack.back();

            Node *nnode = new Node(arr[i]);

            node->children.push_back(nnode);

            stack.push_back(nnode);
        }
        else{
            stack.pop_back();
        }
    }

    return root;
}


// approch-2 using queue and nullptr
Node *linearize(Node *node)
{
    queue<Node *> que;

    que.push(node);

    que.push(nullptr);

    while (!que.empty())
    {
        Node *frontNode = que.front();

        que.pop();

        if (frontNode == nullptr)
        {
            cout << endl;
            
            if (!que.empty())
            {
                que.push(nullptr);
            }
        }
        else
        {
            cout << frontNode->data << " ";

            for (auto &child : frontNode->children)
            {
                que.push(child);
            }
        }
    }
}



int main()
{
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = constructor01(arr);

    linearize(root);

    return 0;
}