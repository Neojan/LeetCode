/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
private:
    vector<int> diff;

public:
    void makeDiff(int n)
    {
        diff.resize(n);
        // for (int i = 1; i < n+1; i++)
        // {
        //     diff[i] = input[i] - diff[i - 1];
        // }
    }

    void diffChange(int first, int last, int seats)
    {
        diff[first] += seats;
        if (last + 1 < this->diff.size())
        {
            diff[last + 1] -= seats;
        }
    }

    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int n = 1001
        this->makeDiff(n);
        for (int i = 0; i < trips.size(); i++)
        {
            this->diffChange(trips[i][1], trips[i][2] - 1, trips[i][0]);
        }
        vector<int> newValue(n);
        newValue[0] = this->diff[0];
        if (newValue[0] > capacity)
        {
            return false;
        }
        for (int i = 1; i < n; i++)
        {
            newValue[i] = newValue[i - 1] + this->diff[i];
            if (newValue[i] > capacity)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
