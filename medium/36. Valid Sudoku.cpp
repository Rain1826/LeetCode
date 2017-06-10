/*Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.*/

/*
思路：
三个数组判断数字是否出现过，分别是判断行、列、子数组
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false}, col[9][9] = {false}, sub[9][9] = {false};
        for(int i = 0;i < board.size();++ i) {
            for(int j = 0;j < board[0].size();++ j) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1',k = i / 3 * 3 + j / 3;
                    if(row[i][num] || col[j][num] || sub[k][num])
                        return false;
                    row[i][num] = col[j][num] = sub[k][num] = true;
                }
            }
        }
        return true;
    }
};
