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
    TreeNode *build_tree(int psi, int pei, int isi, int iei, vector<int> &preorder, vector<int> &inorder)
    {
        if (psi > pei || isi > iei)
            return NULL;
        if (psi == pei)
        {
            TreeNode *root = new TreeNode(preorder[psi]);
            return root;
        }
        TreeNode *root = new TreeNode(preorder[pei]);
        int i = 0;
        while (root->val != inorder[i])
        {
            i++;
        }
        int ll = i - isi;
        int rl = inorder.size() - i - 1;
        root->left = build_tree(psi, psi + ll - 1, isi, i - 1, preorder, inorder);
        root->right = build_tree(psi + ll, pei - 1, i + 1, iei, preorder, inorder);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return build_tree(0, postorder.size() - 1, 0, inorder.size() - 1, postorder, inorder);
    }
};