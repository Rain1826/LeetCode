/*Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]*/

class Solution {
public:
    void myCombination(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& res, int begin) {
        if(target == 0) {
            res.push_back(combination);
            return;
        }
        for(int i = begin;i < candidates.size() && candidates[i] <= target;i ++) {
            if(i > begin && candidates[i] == candidates[i - 1]) continue;   //去重
            combination.push_back(candidates[i]);
            myCombination(candidates, target - candidates[i], combination, res, i + 1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        myCombination(candidates, target, combination, res, 0);
        return res;
    }
};
