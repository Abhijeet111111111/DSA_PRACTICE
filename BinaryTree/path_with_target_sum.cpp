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
    void get_valid_paths(TreeNode *root, int sum, int target, vector<int> temp, vector<vector<int>> &paths)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            if (sum + root->val == target)
            {
                temp.push_back(root->val);
                paths.push_back(temp);
            }
            return;
        }

        // if(sum+root->val < target){
        temp.push_back(root->val);
        get_valid_paths(root->left, sum + root->val, target, temp, paths);
        get_valid_paths(root->right, sum + root->val, target, temp, paths);
        // }
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<vector<int>> paths;
        get_valid_paths(root, 0, targetSum, {}, paths);
        return paths;
    }
};