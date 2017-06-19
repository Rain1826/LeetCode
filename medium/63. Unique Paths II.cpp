/*Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.*/

/*
思路：
同 62.Unique Paths 的动态规划思想类似，只是需要考虑障碍点的dp值为0
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m == 0 || n == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //更新第一行dp
        int index = 0;
        while(index < n && obstacleGrid[0][index] == 0) {
            dp[0][index ++] = 1;
        }
        //更新第一列dp
        index = 0;
        while(index < m && obstacleGrid[index][0] == 0) {
            dp[index ++][0] = 1;
        }
        for(int i = 1;i < m;i ++) {
            for(int j = 1;j < n;j ++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
