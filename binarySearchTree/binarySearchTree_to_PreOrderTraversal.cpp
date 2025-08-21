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
    TreeNode *insert_into_tree(TreeNode *node, TreeNode *root)
    {
        if (!root)
        {
            return node;
        }
        if (root->val < node->val)
        {
            root->right = insert_into_tree(node, root->right);
        }
        else
        {
            root->left = insert_into_tree(node, root->left);
        }
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *node = new TreeNode(preorder[i]);
            insert_into_tree(node, root);
        }
        return root;
    }
};