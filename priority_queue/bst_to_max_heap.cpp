#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*  PROCEDURE :-

    1. store the inorder traversal of the tree in array
    2. Apply preorder traversal and root->val = arr[i++];


*/



struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *sortedArrayToBST(vector<int> nums)
{
    if (!nums.size())
        return NULL;
    int mid = nums.size() / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    vector<int> left_part(nums.begin(), nums.begin() + mid);
    vector<int> right_part(nums.begin() + mid + 1, nums.end());

    root->left = sortedArrayToBST(left_part);
    root->right = sortedArrayToBST(right_part);

    return root;
}

void levelOrder(TreeNode *root)
{
    queue<TreeNode *> qu;
    qu.push(root);
    qu.push(new TreeNode(9999));
    vector<vector<int>> ans;
    vector<int> temp_vec;
    while (qu.size() > 1)
    {
        TreeNode *curr = qu.front();
        qu.pop();
        if (curr && curr->val == 9999)
        {

            qu.push(new TreeNode(9999));
            ans.push_back(temp_vec);
            cout << endl;
            continue;
        }
        if (curr)
        {
            cout << curr->val << " ";
            qu.push(curr->left);
            qu.push(curr->right);
        }
    }
}

void inorder(TreeNode *root, int *arr, int &i)
{
    if (!root)
        return;
    inorder(root->right, arr, i);
    *(arr + i) = root->val;
    i++; 
    inorder(root->left, arr, i);
}

void change_to_max_heap(TreeNode *root, int *inorder_arr, int &i)
{
    if (!root)
        return;
    root->val = *(inorder_arr + i);
    i++;
    change_to_max_heap(root->left, inorder_arr, i);
    change_to_max_heap(root->right, inorder_arr, i);
}

int main()
{
    TreeNode *root = sortedArrayToBST({1, 2, 3, 4, 5, 6, 7, 8});
    levelOrder(root);

    int *arr = (int *)malloc(4 * 8);
    int i = 0;
    inorder(root, arr, i);
    cout << endl
         << endl;
    // for (int i = 0; i < 8; i++)
    // {
    //     cout << *(arr + i) << " ";
    // }
    i = 0;
    change_to_max_heap(root, arr, i);
    levelOrder(root);
}

