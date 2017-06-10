/*Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.*/

/*
题意：解一个数独
思路：
可以考虑“先放置，再判断”的方案。比如这里，首先判断当前位置是否为空，如果为空，那么放置一个元素，检查它是否正确。
如果正确，就继续进行下面的递归（也就是 check(board, i, j) && mySolve(board, i, j + 1) 的作用）。
当函数返回错误之后，将刚刚的数值变为空，再进行下一次尝试即可。
*/

class Solution {
public:
    bool check(vector<vector<char>>& board, int x, int y) {
        int i, j;
        for(i = 0; i < board.size(); i ++) {
            if(i != x && board[i][y] == board[x][y])
                return false;
        }
        for(j = 0; j < board[0].size(); j ++) {
            if(j != y && board[x][j] == board[x][y])
                return false;
        }
        for(i = 3 * (x / 3); i < 3 * (x / 3 + 1); i ++) {
            for(j = 3 * (y / 3); j < 3 * (y / 3 + 1); j ++) {
                if(i != x && j != y && board[i][j] == board[x][y])
                    return false;
            }
        }
        return true;
    }
    bool mySolve(vector<vector<char>>& board, int i, int j) {
        if(i == 9)  return true;
        if(j == 9)  return mySolve(board, i + 1, 0);
        if(board[i][j] != '.')  return mySolve(board, i, j + 1);
        for(char c = '1'; c <= '9'; c ++) {
            board[i][j] = c;
            if(check(board, i, j) && mySolve(board, i, j + 1)) {
                return true;
            }
            board[i][j] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        mySolve(board, 0, 0);
    }
};
