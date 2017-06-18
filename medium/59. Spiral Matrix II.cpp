/*Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]*/

/*
思路：
和数组顺时针打印类似，代码实现问题
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 1));
        if(n < 2)   return res;
        int curNum = 1;
        int round = (n - 1) / 2 + 1;
        for(int x = 0;x < round;x ++){
            //左->右
            for(int i = x;i < n - x;i ++){
                res[x][i] = curNum ++;
            }
            //上->下
            for(int i = x + 1;i < n - x;i ++){
                res[i][n - 1 - x] = curNum ++;
            }
            //右->左
            for(int i = n - 2 - x;(i >= x) && (n - 1 - x != x);i --){
                res[n - 1 - x][i] = curNum ++;
            }
            //下->上
            for(int i = n - 2 - x;(i > x) && (n - 1 - x != x);i --){
                res[i][x] = curNum ++;
            }
        }
        return res;
    }
};
