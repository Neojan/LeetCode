/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        if (grid[i][j] == '0')
            return;

        grid[i][j] = '0'; // 淹没
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j-1);
        return;
    }
    int  numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }

            }
        }
        return res;
    }
};
// @lc code=end

