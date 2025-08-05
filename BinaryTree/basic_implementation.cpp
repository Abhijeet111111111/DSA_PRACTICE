#include <iostream>
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

int sumOfNodes(Node *root)
{
    if (!root)
        return 0;
    return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
}

void display(Node *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

int size_of_tree(Node *root)
{
    if (!root)
        return 0;
    return 1 + size_of_tree(root->left) + size_of_tree(root->right);
}

int max_value_of_tree(Node *root)
{
    if (!root)
        return -9999;
    return max(root->val, (max(max_value_of_tree(root->left), max_value_of_tree(root->right))));
}

int no_of_levels(Node* root){
    if(!root) return 0;
    int l = no_of_levels(root->left);
    int r = no_of_levels(root->right);
    return 1 + max(l,r);
}

int main()
{

    Node *root = new Node(1);
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);
    Node *d = new Node(999);
    Node *e = new Node(6);
    Node *f = new Node(100);
    Node *g = new Node(99);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    b->left = e;
    b->right = f;

    c->left = g;

    display(root);
    cout << endl;
    cout << sumOfNodes(root);
    cout << endl;
    cout << size_of_tree(root) << endl;
    cout << max_value_of_tree(root) << endl;
    cout<<no_of_levels(root);
}