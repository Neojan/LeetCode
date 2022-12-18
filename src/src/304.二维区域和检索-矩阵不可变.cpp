/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
private:
    vector<vector<int>> preMatrix;


public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size() + 1;
        int n = matrix[0].size() + 1;
        this->preMatrix.resize(m, vector<int>(n));
        for (int i = 1; i<m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                preMatrix[i][j] = preMatrix[i][j - 1] + preMatrix[i - 1][j] - preMatrix[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return this->preMatrix[row2 + 1][col2 + 1] - this->preMatrix[row2 + 1][col1] - this->preMatrix[row1][col2+1] + this->preMatrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

