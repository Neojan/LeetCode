/**
1. 题目
由空地和墙组成的迷宫中有一个球。
 球可以向上下左右四个方向滚动，但在遇到墙壁前不会停止滚动。
 当球停下时，可以选择下一个方向。

给定球的起始位置，目的地和迷宫，判断球能否在目的地停下。

迷宫由一个0和1的二维数组表示。 1表示墙壁，0表示空地。
 你可以假定迷宫的边缘都是墙壁。
 起始位置和目的地的坐标通过行号和列号给出。

输入 1: 迷宫由以下二维数组表示

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

输入 2: 起始位置坐标 (rowStart, colStart) = (0, 4)
输入 3: 目的地坐标 (rowDest, colDest) = (4, 4)

输出: true

 输入 1: 迷宫由以下二维数组表示

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

输入 2: 起始位置坐标 (rowStart, colStart) = (0, 4)
输入 3: 目的地坐标 (rowDest, colDest) = (3, 2)

输出: false
*/

class Solution {
    int                 m, n;
    vector<vector<int>> dir   = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    bool                found = false;

public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(maze, start, destination, visited);
#if 0 //打印路径
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
#endif
        return found;
    }
    void dfs(vector<vector<int>> &maze, vector<int> start, vector<int> &destination, vector<vector<bool>> &visited)
    {
        if (found)
        {
            return;
        }
        if (start[0] < 0 || start[0] >= m || start[1] < 0 || start[1] >= n || maze[start[0]][start[1]] || visited[start[0]][start[1]])
        {
            return;
        }

        visited[start[0]][start[1]] = true;
        if (start[0] == destination[0] && start[1] == destination[1])
        {
            found = true;
            return;
        }

        dfs(maze, {start[0] + 1, start[1]}, destination, visited);
        dfs(maze, {start[0] - 1, start[1]}, destination, visited);
        dfs(maze, {start[0], start[1] + 1}, destination, visited);
        dfs(maze, {start[0], start[1] - 1}, destination, visited);
    }
#if 0
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[start[0]][start[1]] = true;
        dfs(maze, start, destination, visited);
        return found;
    }

    void dfs(vector<vector<int>> &maze, vector<int> start, vector<int> &destination, vector<vector<bool>> &visited)
    {
        if (found)
            return;
        int i = start[0], j = start[1], x, y, k;
        if (i == destination[0] && j == destination[1])
        {
            found = true;
            return;
        }
        for (k = 0; k < 4; ++k)
        {
            x = i;
            y = j;
            while (x + dir[k][0] >= 0 && x + dir[k][0] < m && y + dir[k][1] >= 0 && y + dir[k][1] < n && maze[x + dir[k][0]][y + dir[k][1]] == 0)
            {
                x += dir[k][0];
                y += dir[k][1];
                // visited[x][y] = true;//不能加这一句，一会下面进不了队列
            }
            if (!visited[x][y])
            {
                visited[x][y] = true;
                dfs(maze, {x, y}, destination, visited);
            }
        }
    }
#endif
};

void testMaze()
{
    vector<vector<int>> mazeInput;
    vector<int>         start       = {0, 4};
    vector<int>         destination = {4, 4};
    vector<int>         v1          = {0, 0, 1, 0, 0};
    vector<int>         v2          = {0, 0, 0, 0, 1};
    vector<int>         v3          = {0, 1, 0, 1, 0};
    vector<int>         v4          = {1, 1, 0, 1, 1};
    vector<int>         v5          = {0, 1, 0, 0, 0};

    mazeInput.push_back(v1);
    mazeInput.push_back(v2);
    mazeInput.push_back(v3);
    mazeInput.push_back(v4);
    mazeInput.push_back(v5);
    Solution s;
    bool     found = s.hasPath(mazeInput, start, destination);
    cout << found << endl;
}
