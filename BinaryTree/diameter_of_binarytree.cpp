#include <iostream>
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
    int no_of_levels(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = no_of_levels(root->left);
        int r = no_of_levels(root->right);
        return 1 + max(l, r);
    }
    int distance(TreeNode *root)
    {
        int l = no_of_levels(root->left);
        int r = no_of_levels(root->right);
        return l + r;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return -999;
        int a = distance(root);
        int b = diameterOfBinaryTree(root->left);
        int c = diameterOfBinaryTree(root->right);
        return max(a, max(b, c));
    }
};