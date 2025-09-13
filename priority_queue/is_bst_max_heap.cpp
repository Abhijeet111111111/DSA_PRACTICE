#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int sizeOfBST(Node *root)
{
    if (!root)
        return 0;
    return 1 + sizeOfBST(root->left) + sizeOfBST(root->right);
}

bool isCBT(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int count = 0;
    int s = sizeOfBST(root);
    while (s > count)
    {
        Node *curr = q.front();
        q.pop();
        if (curr)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
        count++;
    }
    while (q.size())
    {
        Node *curr = q.front();
        q.pop();
        if (curr)
            return false;
    }
    return true;
}

bool isMax(Node *root)
{
    if (!root)
        return true;
    if (root->left && root->left->val > root->val)
        return false;
    if (root->right && root->right->val > root->val)
        return false;
    return (isMax(root->left) && isMax(root->right));
}

void display(Node *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

int main()
{

    Node *root = new Node(20);
    Node *a = new Node(15);
    Node *b = new Node(10);
    Node *c = new Node(8);
    Node *d = new Node(11);
    Node *e =  new Node(6);
    Node *f = NULL;
    Node *g = new Node(99);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    // b->left = e;
    b->right = f;

    // c->left = g;

    if (isCBT(root) && isMax(root))
        cout << "Yes,BST is MaxHeap";
    else
        cout << "NO,BST is not a MaxHeap";
}