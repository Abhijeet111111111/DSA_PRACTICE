#include <iostream>
#include <vector>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p)
            return p;
        else if (root == q)
            return q;
        if (root == NULL)
            return NULL;

        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        if (p == q)
            return p;
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if (p == q)
            return p;

        if (l && r)
        {
            p = q = root;
            return root;
        }

        if (l)
            return l;
        return r;
    }
};