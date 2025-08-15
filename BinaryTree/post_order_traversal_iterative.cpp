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
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> vec;
        stack<TreeNode *> st;
        stack<TreeNode *> visited;
        st.push(root);
        while (st.size())
        {
            TreeNode *curr = st.top();
            if (curr)
            {

                TreeNode *visited_node = NULL;
                if (visited.size())
                    visited_node = visited.top();

                if (curr == visited_node)
                {
                    st.pop();
                    visited.pop();
                    vec.push_back(curr->val);
                }
                else
                {
                    if (curr->right)
                        st.push(curr->right);
                    if (curr->left)
                        st.push(curr->left);
                    visited.push(curr);
                }
            }
        }
        return vec;
    }
};