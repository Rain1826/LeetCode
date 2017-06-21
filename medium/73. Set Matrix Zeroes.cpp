/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.*/

/*
思路：
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
将上面 O(m + n) 的算法中的标记空间转移到 matrix 的第一行和第一列
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false;  //第一行是否包括0
        bool firstColZero = false;  //第一列是否包括0
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0;i < row;i ++) {
            for(int j = 0;j < col;j ++) {
                if(matrix[i][j] == 0) {
                    if(i == 0)  firstRowZero = true;
                    if(j == 0)  firstColZero = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1;i < row;i ++) {
            for(int j = 1;j < col;j ++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(firstColZero) {
            for(int i = 0;i < row;i ++)
                matrix[i][0] = 0;
        }
        if(firstRowZero) {
            for(int j = 0;j < col;j ++)
                matrix[0][j] = 0;
        }
    }
};
