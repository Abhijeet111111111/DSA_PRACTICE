#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode *root)
    {

        if (!root)
            return {};

        vector<int> right_side_view;

        queue<TreeNode *> qu;
        qu.push(root);
        TreeNode *sep = new TreeNode(999);
        qu.push(sep);
        while (qu.size() != 1)
        {
            TreeNode *curr = qu.front();
            qu.pop();
            if (qu.front() == sep)
            {
                right_side_view.push_back(curr->val);
            }
            if (curr == sep)
            {
                qu.push(curr);
            }
            if (curr->left)
                qu.push(curr->left);
            if (curr->right)
                qu.push(curr->right);
        }

        return right_side_view;
    }
};