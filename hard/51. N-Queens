/*The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]*/

/*
思路：
N皇后问题，回溯法
*/

class Solution {
public:
    bool canPlace(vector<string>& nQueens, int row, int col, int n) {
        //每行只有一个
        for(int i = 0;i != col;i ++) {
            if(nQueens[row][i] == 'Q')  return false;
        }
        //每列只有一个
        for(int i = 0;i != row;i ++) {
            if(nQueens[i][col] == 'Q')  return false;
        }
        //对角线只有一个
        for(int i = row - 1, j = col + 1;i >= 0 && j < n;i --, j ++) {
            if(nQueens[i][j] == 'Q')    return false;
        }
        for(int i = row - 1, j = col - 1;i >= 0 && j >= 0;i --, j --) {
            if(nQueens[i][j] == 'Q')    return false;
        }
        return true;
    }
    void mysolveNQueens(vector<vector<string>>& res, vector<string>& nQueens, int row, int n) {
        if(n == row) {
            res.push_back(nQueens);
            return;
        }
        for(int col = 0;col < n; col ++) {
            if(canPlace(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                mysolveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> NQueens(n, string(n, '.'));
        mysolveNQueens(res, NQueens, 0, n);
        return res;
    }
};
