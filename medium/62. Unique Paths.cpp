/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.*/

/*
思路：
1.可以用排列组合知识知道最终结果为 (m + n)! / (m! * n!)
  但直接把每个阶乘求除法的话会溢出，因此将该过程转化为分子和分母分别作乘法和除法
2.动态规划
  对于格点(i,j)。由于只能从上格点(i-1,j)或左格点(i,j-1)到达，并且两者路径是不重复的
  因此dp[i][j] = dp[i-1][j]+dp[i][j-1]
*/

//排列组合
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) {
            return 1;
        }
        if(m < n) {
            swap(m, n);
        }
        int N = m + n - 2;
        long long res = 1;
        for(int i = m, j = 1;i <= N;i ++, j ++) {
            res *= i;
            res /= j;
        }
        return (int)res;
    }
};

//动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1;i < m;i ++) {
            for(int j = 1;j < n;j ++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
