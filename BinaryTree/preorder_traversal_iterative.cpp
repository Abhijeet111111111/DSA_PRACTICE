#include <iostream>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> vec;
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
                    vec.push_back(curr->val);
                }
            }
        }
        return vec;
    }
};