/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
private:
    vector<int> preNums;

public:
    NumArray(vector<int> &nums)
    {
        preNums.resize(nums.size() + 1);
        for (int i = 1; i < preNums.size(); i++)
        {
            preNums[i] = preNums[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int left, int right)
    {
        return this->preNums[right + 1] - this->preNums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

