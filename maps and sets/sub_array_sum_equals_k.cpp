#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[nums[0]] = 1;
        mp[0]++;
        int c = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i] + nums[i - 1];
            int diff = nums[i] - k;
            c += mp[diff];
            mp[nums[i]]++;
        }
        if (nums[0] == k)
            c++;
        return c;
    }
};