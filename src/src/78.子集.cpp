/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int>         cur_list;
    void                dfs(vector<int> &nums, int cur_index)
    {
        res.push_back(cur_list);
        for (int i = cur_index; i < nums.size(); i++)
        {
            cur_list.push_back(nums[i]);
            dfs(nums, i + 1);
            cur_list.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }
};
// @lc code=end
