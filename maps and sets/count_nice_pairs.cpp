#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int rev(int n)
    {
        int r = 0;
        while (n)
        {
            r *= 10;
            r += n % 10;
            n /= 10;
        }
        return r;
    }
    long nCr(long n)
    {
        return ((n * (n - 1)) / 2) % 1000000007;
    }

    int countNicePairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int d = nums[i] - rev(nums[i]);
            mp[d]++;
        }

        for (auto ele : mp)
        {
            count += nCr(ele.second);
        }
        return count % 1000000007;
    }
};