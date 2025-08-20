#include <iostream>
#include <climits>
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
    long right_min(TreeNode *root)
    {
        if (!root)
            return LONG_MAX;
        long l = right_min(root->left);
        long r = right_min(root->right);
        return min((min(l, r)), (long)root->val);
    }
    long left_max(TreeNode *root)
    {
        if (!root)
            return LONG_MIN;
        long l = left_max(root->left);
        long r = left_max(root->right);
        return max((max(l, r)), (long)root->val);
    }

    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        if (root->val >= right_min(root->right))
            return false;
        if (root->val <= left_max(root->left))
            return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};