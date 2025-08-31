#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int countDistinctIntegers(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
            int rev = 0;
            while (nums[i])
            {
                rev *= 10;
                rev += nums[i] % 10;
                nums[i] /= 10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};