/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        // dp[i][j][k]，第i天，交易了j次，当前是否持有（0未持有，1持有）
        int                         n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        // 第0天，无论交易多少次，不持有股票为0，持有股票利润为-prices[0]
        for (int j = 0; j <= k; ++j)
        {
            dp[0][j][0] = 0;
            dp[0][j][1] = -prices[0];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                if (j == 0)
                {
                    // 前一天交易0次，不持有，今天不动
                    dp[i][j][0] = dp[i - 1][j][0];
                    // 前一天交易0次，不持有，今天买入  前一天交易0次，持有，今天不动
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
                }
                else
                {
                    // 前一天交易j次，不持有，今天不动   前一天交易j-1次，持有一笔，今天卖出
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
                    // 前一天交易j次，持有一笔，今天不动  前一天交易j次，不持有，今天买入
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
                }
            }
        }
        // 最后一天不持有股票
        int ans = 0;
        for (int j = 0; j <= k; ++j)
        {
            ans = max(ans, dp[n - 1][j][0]);
        }
        return ans;
    }
};
// @lc code=end

