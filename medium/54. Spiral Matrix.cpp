/*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].*/

/*
思路：
顺时针打印矩阵，先判断要打印的圈数，注意判断是否重复打印
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0)  return res;
        int col = matrix[0].size();
        int row = matrix.size();
        int num = (((row <= col)?row:col) - 1)/2 + 1;
        for(int x = 0;x < num;x ++){
            //左->右
            for(int i = x;i < col - x;i ++){
                res.push_back(matrix[x][i]);
            }
            //上->下
            for(int i = x + 1;i < row - x;i ++){
                res.push_back(matrix[i][col - 1 - x]);
            }
            //右->左
            for(int i = col - 2 - x;(i >= x) && (row - 1 - x != x);i --){
                res.push_back(matrix[row - 1 - x][i]);
            }
            //下->上
            for(int i = row - 2 - x;(i > x) && (col - 1 - x != x);i --){
                res.push_back(matrix[i][x]);
            }
        }
        return res;
    }
};
