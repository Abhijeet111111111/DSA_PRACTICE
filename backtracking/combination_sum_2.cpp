#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    bool f(vector<int> &candidates, int target, vector<int> &temp, int st)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return true;
        }
        if (st >= candidates.size())
            return false;

        for (int i = st; i < candidates.size(); i++)
        {
            if (i != 0 and candidates[i] == candidates[i - 1])
                continue;
            if (!candidates[i])
                continue;
            if ((target - candidates[i]) < 0)
                return false;
            int n = candidates[i];
            temp.push_back(n);
            candidates[i] = 0;
            bool res = f(candidates, target - n, temp, i + 1);
            candidates[i] = n;
            temp.pop_back();
        }
        return true;
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        f(candidates, target, temp, 0);
        return ans;
    }
};