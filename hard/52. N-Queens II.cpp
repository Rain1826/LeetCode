/*Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.*/

/*
思路：回溯法
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
    void mysolveNQueens(int& res, vector<string>& nQueens, int row, int n) {
        if(n == row) {
            res ++;
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
    int totalNQueens(int n) {
        int res = 0;
        vector<string> NQueens(n, string(n, '.'));
        mysolveNQueens(res, NQueens, 0, n);
        return res;
    }
};
