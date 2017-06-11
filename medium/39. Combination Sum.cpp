/*Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]*/

/*
思路：
先将当前值放入，递归，再取出，继续下次循环
*/

class Solution {
public:
    void myCombinationSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combination, int begin) {
        if(target == 0) {
            res.push_back(combination);
            return;
        }
        for(int i = begin;i < candidates.size() && candidates[i] <= target;i ++) {
            combination.push_back(candidates[i]);
            myCombinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        myCombinationSum(candidates, target, res, combination, 0);
        return res;
    }
};
