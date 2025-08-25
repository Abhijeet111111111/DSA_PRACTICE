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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                // find predecessor
                TreeNode *pred = curr->left;
                while (pred->right)
                    pred = pred->right;

                pred->right = curr;
                TreeNode *l = curr->left;
                curr->left = NULL;
                curr = l;
            }
            else
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};