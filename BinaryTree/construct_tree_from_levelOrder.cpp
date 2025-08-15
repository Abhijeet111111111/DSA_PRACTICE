#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;
    Node(int val)
    {
        this->val = val;
        // left = right = NULL;
    }
};

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
    Node *root = get_tree_from_arr({1, 2, 3, 4, 5, NULL, 6, NULL, NULL});
    level_order_traversl(root, 10);
}