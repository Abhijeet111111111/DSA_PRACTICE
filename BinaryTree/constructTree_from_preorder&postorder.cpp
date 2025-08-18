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
    TreeNode *constructTree(int spre, int epre, int spo, int epo, vector<int> &preorder, vector<int> &postorder)
    {
        if (spre > epre or spo > epo)
            return NULL;
        TreeNode *root = new TreeNode(preorder[spre]);
        if (spre == epre)
            return root;
        int i = 0;
        while (preorder[spre + 1] != postorder[i])
            i++;
        int ll = i + 1 - spo;
        int rl = epo - i - 1;
        root->left = constructTree(spre + 1, spre + ll, spo, i, preorder, postorder);
        root->right = constructTree(spre + ll + 1, epre, i + 1, i + rl, preorder, postorder);
        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return constructTree(0, preorder.size() - 1, 0, postorder.size() - 1, preorder, postorder);
    }
};