#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;
    Node(int val)
    {
        left = right = NULL;
        this->val = val;
    }
};

void nth_level(Node *root, int lvl)
{
    if (!root)
    {
        cout << "* ";
        return;
    }
    if (lvl == 1)
    {
        cout << root->val << " ";
        return;
    }
    nth_level(root->left, lvl - 1);
    nth_level(root->right, lvl - 1);
}

void level_order_traversl(Node *root, int no_of_lvl)
{
    for (int i = 1; i <= no_of_lvl; i++)
    {
        nth_level(root, i);
        cout << endl;
    }
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
    b->right = NULL;

    c->left = g;
    c->right = f;

    // nth_level(root, 4);
    level_order_traversl(root, 10);
}