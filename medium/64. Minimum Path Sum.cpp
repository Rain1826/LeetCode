/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.*/

/*
思路：
动态规划：dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int curSum = 0;
        //更新第一行
        for(int i = 0;i < n;i ++) {
            curSum += grid[0][i];
            dp[0][i] = curSum;
        }
        curSum = 0;
        //更新第一列
        for(int i = 0;i < m;i ++) {
            curSum += grid[i][0];
            dp[i][0] = curSum;
        }
        for(int i = 1;i < m;i ++) {
            for(int j = 1;j < n;j ++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
