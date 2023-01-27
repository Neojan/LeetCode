/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int search_left_bound(vector<int> &nums, int target)
    {
        int mid = 0, left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        if (left == nums.size()) return -1;
        return (nums[left] == target) ? left : -1;
    }
    int search_right_bound(vector<int> &nums, int target)
    {
        int mid = 0, left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                left = mid + 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        if (left - 1 < 0)
            return -1;
        return (nums[left - 1] == target) ? left - 1 : -1;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = search_left_bound(nums, target);
        int right = search_right_bound(nums, target);
        return vector<int>{left, right};
    }
};
// @lc code=end
