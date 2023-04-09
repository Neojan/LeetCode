class Solution {
public:
    int waysToChange(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int                 coins[3] = {1, 3, 5};
        vector<vector<int>> dp(3, vector<int>(n + 1, 0));

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }

                dp[i][j] = dp[i - 1][j];
                if (j - coins[i] >= 0)
                {
                    dp[i][j] = dp[i][j] + dp[i][j - coins[i]];
                }
            }
        }

        return dp[2][n];
    }
};


int testCoin(void)
{
    Solution s;
    // 全1
    // 1 1 1 3 5
    // 8个1,3
    // 6个1， 5
    // 1,1,3,3,3
    // 5个1,3 ，3
    // 1,5,5
    // 3,3,5
    int way = s.waysToChange(11);
    cout << way << endl; //8
    return 0;
}