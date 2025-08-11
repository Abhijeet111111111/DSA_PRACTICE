#include <iostream>
#include <vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> v;
        vector<vector<int>> ans;
        TreeNode *sep = new TreeNode(999);
        q.push(sep);
        while (q.size() != 1)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr == sep)
            {
                ans.push_back(v);
                v = {};
                q.push(sep);
            }
            else if (curr)
            {
                v.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        if (v.size())
            ans.push_back(v);
        return ans;
    }
};