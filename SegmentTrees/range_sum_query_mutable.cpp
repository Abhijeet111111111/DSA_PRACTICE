#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class NumArray
{
public:
    vector<int> st;
    vector<int> nums;
    void buildTree(int lo, int hi, int i)
    {
        if (lo == hi)
        {
            st[i] = nums[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildTree(lo, mid, 2 * i + 1);
        buildTree(mid + 1, hi, 2 * i + 2);
        st[i] = st[2 * i + 1] + st[2 * i + 2];
    }
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        this->st.resize(4 * nums.size());
        buildTree(0, nums.size() - 1, 0);
    }
    void updateSt(int &id, int &ex, int lo, int hi, int i)
    {
        if (id < lo or id > hi)
            return;
        if (hi == lo)
        {
            this->st[i] = this->st[i] + ex;
            // cout<<lo<<" "<<hi<<" "<<st[i]<<endl;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        updateSt(id, ex, lo, mid, 2 * i + 1);
        updateSt(id, ex, mid + 1, hi, 2 * i + 2);

        this->st[i] = this->st[i] + ex;
        // cout<<lo<<" "<<hi<<" "<<st[i]<<endl;
    }
    void update(int index, int val)
    {
        int ex = val - this->nums[index];
        this->nums[index] = val;
        updateSt(index, ex, 0, this->nums.size() - 1, 0);
    }
    int getSum(int i, int lo, int hi, int &l, int &r)
    {
        if (l <= lo and r >= hi)
            return st[i];
        if (l > hi or r < lo)
            return 0;
        int mid = lo + (hi - lo) / 2;
        return getSum(2 * i + 1, lo, mid, l, r) + getSum(2 * i + 2, mid + 1, hi, l, r);
    }

    int sumRange(int left, int right)
    {
        return getSum(0, 0, this->nums.size() - 1, left, right);
    }
};