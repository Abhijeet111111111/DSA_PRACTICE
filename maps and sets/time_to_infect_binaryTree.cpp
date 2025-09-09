#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> mp;
    void get_parents(TreeNode *root, TreeNode *parent)
    {
        if (!root)
            return;
        mp[root] = parent;
        get_parents(root->left, root);
        get_parents(root->right, root);
    }
    TreeNode *get_node(TreeNode *root, int s)
    {
        if (!root)
            return NULL;
        if (root->val == s)
            return root;
        TreeNode *l = get_node(root->left, s);
        TreeNode *r = get_node(root->right, s);
        if (l)
            return l;
        return r;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        TreeNode *infected_node = get_node(root, start);
        get_parents(root, NULL);
        queue<TreeNode *> qu;
        qu.push(infected_node);
        qu.push(new TreeNode(-999));
        int c = 0;
        while (qu.size() > 1)
        {
            TreeNode *curr = qu.front();
            TreeNode *parent = mp[curr];
            TreeNode *lc = curr->left;
            TreeNode *rc = curr->right;
            qu.pop();
            if (curr->val == -999)
            {
                c++;
                qu.push(new TreeNode(-999));
            }
            curr->val = -1;
            if (parent && parent->val != -1)
                qu.push(parent);
            if (lc && lc->val != -1)
                qu.push(lc);
            if (rc && rc->val != -1)
                qu.push(rc);
        }
        return c;
    }
};