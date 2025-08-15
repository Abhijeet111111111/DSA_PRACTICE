#include <iostream>
#include <vector>
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

void display(Node *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

void print_left_boundary(Node *root)
{
    if (!root)
        return;
    if (root->left or root->right)
        cout << root->val << " ";
    if (root->left)
        print_left_boundary(root->left);
    else
        print_left_boundary(root->right);
}
void print_right_boundary(Node *root)
{
    if (!root)
        return;
    if (root->right)
        print_right_boundary(root->right);
    else
        print_right_boundary(root->left);
    if (root->left or root->right)
        cout << root->val << " ";
}

void print_leaf_boundary(Node *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        cout << root->val << " ";
    print_leaf_boundary(root->left);
    print_leaf_boundary(root->right);
}

void print_boundary_values(Node *root)
{
    cout << root->val << " ";
    // left boundary
    print_left_boundary(root->left);

    // leaves
    print_leaf_boundary(root);

    // right boudary in reverseOrder
    print_right_boundary(root->right);
}

Node *get_tree_from_arr(vector<int> arr)
{
    Node *root = new Node(arr[0]);
    queue<Node *> qu;
    qu.push(root);
    int i = 1;
    while (qu.size())
    {
        Node *curr = qu.front();
        qu.pop();
        if (!curr)
            continue;
        Node *l = NULL;
        Node *r = NULL;
        if (i < arr.size() && arr[i])
            l = new Node(arr[i]);
        if (i < arr.size() && arr[i + 1])
            r = new Node(arr[i + 1]);
        curr->left = l;
        curr->right = r;
        qu.push(l);
        qu.push(r);
        i += 2;
    }

    return root;
}

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
    vector<int> v = {1, 2, 3, 4, 5, NULL, 6, 7, NULL, 8, NULL, 9, 10, NULL, 11, NULL, 12, NULL, 13, NULL, 14, 15, 16, NULL, 17, NULL, NULL, 18, NULL, 19, NULL, NULL, NULL, 20, 21, 22, 23, NULL, 24, 25, 26, 29, NULL, NULL, 28, NULL, NULL};

    Node *root = get_tree_from_arr(v);
    // level_order_traversl(root, 10);
    cout << endl;
    print_boundary_values(root);
}