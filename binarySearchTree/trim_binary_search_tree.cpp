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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return NULL;
        while (root->left && root->left->val < low)
        {
            root->left = root->left->right;
        }
        while (root->right && root->right->val > high)
        {
            root->right = root->right->left;
        }
        while (root && root->val > high)
        {
            root = root->left;
        }
        while (root && root->val < low)
        {
            root = root->right;
        }
        if (root)
            trimBST(root->left, low, high);
        if (root)
            trimBST(root->right, low, high);
        return root;
    }
};