/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]*/

/*
思路：
括号匹配，找到所有的组合，递归
*/

class Solution {
public:
    void myGenerate(vector<string> &ans, string s, int leftNum, int rightNum) {
        if(leftNum == 0 && rightNum == 0) {
            ans.push_back(s);
        }
        if(leftNum > 0) {
            myGenerate(ans, s + '(', leftNum - 1, rightNum);
        }
        if(rightNum > 0 && leftNum < rightNum) {
            myGenerate(ans, s + ')', leftNum, rightNum - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        myGenerate(ans, s, n, n);
        return ans;
    }
};
