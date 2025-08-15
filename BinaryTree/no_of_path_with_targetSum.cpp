#include <iostream>
#include <climits>
#include <stack>
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
    void get_valid_paths(TreeNode *root, long long sum, int target, int &count)
    {
        if (!root)
            return;
        long long ts = sum + root->val;
        if (ts > INT_MAX)
            return;
        if (ts < INT_MIN)
            return;
        if (sum + root->val == target)
        {
            count++;
        }

        get_valid_paths(root->left, sum + root->val, target, count);
        get_valid_paths(root->right, sum + root->val, target, count);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        int count = 0;
        if (!root)
            return 0;
        stack<TreeNode *> st;
        st.push(root);
        stack<TreeNode *> visited;
        while (st.size())
        {
            TreeNode *curr = st.top();
            if (curr)
            {
                TreeNode *visited_node = NULL;
                if (visited.size())
                    visited_node = visited.top();
                if (visited_node == curr)
                {
                    visited.pop();
                    st.pop();
                    if (curr->right)
                        st.push(curr->right);
                }
                else
                {
                    visited.push(curr);
                    if (curr->left)
                        st.push(curr->left);
                    get_valid_paths(curr, 0, targetSum, count);
                }
            }
        }
        return count;
    }
};