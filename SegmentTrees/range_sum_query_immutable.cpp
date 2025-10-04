#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class NumArray
{
public:
    vector<int> preSum;
    NumArray(vector<int> &nums)
    {
        this->preSum.resize(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            this->preSum[i] = nums[i] + this->preSum[i - 1];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return this->preSum[right];
        }
        return this->preSum[right] - this->preSum[left - 1];
    }
};