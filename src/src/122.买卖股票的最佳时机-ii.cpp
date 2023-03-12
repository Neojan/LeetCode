/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 不限制交易次数
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));// n表示天，2表示持有或卖出
        dp[0][0]     = 0;
        dp[0][1]     = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);//卖出或者不动
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);//买入或不动
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

