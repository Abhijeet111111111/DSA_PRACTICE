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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        stack<TreeNode *> st;
        st.push(root);
        while (st.size())
        {
            TreeNode *curr = st.top();
            if (curr)
            {
                if (curr->left && curr->left->val != -101)
                {
                    st.push(curr->left);
                }
                else
                {
                    vec.push_back(curr->val);
                    curr->val = -101;
                    st.pop();
                    st.push(curr->right);
                }
            }
            else
                st.pop();
        }
        return vec;
    }
};