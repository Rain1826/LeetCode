/*Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]*/

/*
思路：Backtracking典型题
*/

class Solution {
public:
    void mysubsets(vector<vector<int>>& res, vector<int> nums, vector<int> subset, int begin, int end, int n) {
        if(0 == n) {
            res.push_back(subset);
            return;
        }
        for(int i = begin;i <= end;i ++) {
            subset.push_back(nums[i]);
            mysubsets(res, nums, subset, i + 1, end, n - 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        for(int i = 0;i <= nums.size();i ++) {
            mysubsets(res, nums, subset, 0, nums.size() - 1, i);
        }
        return res;
    }
};
