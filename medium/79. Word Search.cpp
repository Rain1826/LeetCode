/*Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.*/

/*
思路：
DFS，每走一步就把当前位置的字符设为'\0'防止走回头路
*/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j) {
        if(word == "")  return true;
        bool ans = false;
        if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == word[0]) {
            board[i][j] = '\0';
            ans = dfs(board, word.substr(1), i + 1, j) ||
                  dfs(board, word.substr(1), i - 1, j) ||
                  dfs(board, word.substr(1), i, j + 1) ||
                  dfs(board, word.substr(1), i, j - 1);
            board[i][j] = word[0];
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i < board.size();i ++) {
            for(int j = 0;j < board[0].size();j ++) {
                if(dfs(board, word, i, j))  return true;
            }
        }
        return false;
    }
};
