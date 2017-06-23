/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/

/*
思路：Backtracking典型题
*/

class Solution {
public:
    void mycombine(vector<vector<int>>& res, vector<int> combination, int begin, int end, int k) {
        if(0 == k) {
            res.push_back(combination);
            return;
        }
        for(int i = begin;i <= end;i ++) {
            combination.push_back(i);
            mycombine(res, combination, i + 1, end, k - 1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> combination;
        mycombine(res, combination, 1, n, k);
        return res;
    }
};
