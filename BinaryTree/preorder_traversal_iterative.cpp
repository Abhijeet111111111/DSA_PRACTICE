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
        while (st.size())
        {
            TreeNode *t = NULL;
            if (st.top())
                t = st.top();
            if (!t)
            {
                st.pop();
                continue;
            }
            vec.push_back(t->val);
            st.pop();
            if (t->right)
                st.push(t->right);
            if (t->left)
                st.push(t->left);
        }
        return vec;
    }
};