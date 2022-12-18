/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
private:
    vector<int> diff;

public:
    void makeDiff(int n)
    {
        diff.resize(n);//for last == length
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

    vector<int> makeNew(int n)
    {
        vector<int> newValue(n);
        newValue[0] = this->diff[0];

        for (int i = 1; i < n; i++)
        {
            newValue[i] = newValue[i - 1] + this->diff[i];
        }
        return newValue;
    }

    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        this->makeDiff(n);
        for (int i = 0; i < bookings.size(); i++)
        {
            this->diffChange(bookings[i][0]-1, bookings[i][1]-1, bookings[i][2]);
        }
        return this->makeNew(n);
    }
};
// @lc code=end

