/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vistor;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = vistor.find(target - nums[i]);
            if (it != vistor.end())
            {
                return {it->second, i};
            }
            // vistor[nums[i]]=i;
            vistor.emplace(nums[i], i);
        }
        return {};
    }
};
// @lc code=end

