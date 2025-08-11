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
    void path_to_leaf(TreeNode *root, vector<string> &str, string s)
    {
        if (!root)
            return;
        path_to_leaf(root->left, str, s + to_string(root->val) + "->");
        path_to_leaf(root->right, str, s + to_string(root->val) + "->");
        if (!root->left && !root->right)
            str.push_back(s + to_string(root->val));
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> str;
        path_to_leaf(root, str, "");
        return str;
    }
};