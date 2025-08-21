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
    int totalValue = 0;
    TreeNode *bstToGst(TreeNode *root)
    {
        if (!root)
            return NULL;
        bstToGst(root->right);
        root->val = root->val + totalValue;
        totalValue = root->val;
        bstToGst(root->left);
        return root;
    }
};