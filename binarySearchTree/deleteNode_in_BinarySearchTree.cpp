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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return NULL;
        if (root->val == key)
        {
            if (!root->left && !root->right)
                return NULL;
            if (root->left && !root->right)
                return root->left;
            if (!root->left && root->right)
                return root->right;
            if (root->left && root->right)
            {
                TreeNode *suc = root->right;
                while (suc->left)
                    suc = suc->left;
                deleteNode(root, suc->val);
                root->val = suc->val;
                deleteNode(root->right, suc->val);
            }
        }
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};