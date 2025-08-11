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
        st.push(root);
        while (st.size())
        {
            TreeNode *curr = st.top();
            if (curr)
            {
                if (!curr->left && !curr->right)
                {
                    vec.push_back(curr->val);
                    st.top()->val = -101;
                    st.top() = NULL;
                }
                else if (curr->left && (curr->left->val == -101))
                {
                    vec.push_back(curr->val);
                    st.top()->val = -101;
                    st.top() = NULL;
                }
                else if (curr->right && (curr->right->val == -101))
                {
                    vec.push_back(curr->val);
                    st.top()->val = -101;
                    st.top() = NULL;
                }
                else
                {
                    st.push(curr->right);
                    st.push(curr->left);
                }
            }
            else
                st.pop();
        }
        return vec;
    }
};