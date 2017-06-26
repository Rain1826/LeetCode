/*Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]*/

/*
思路：Backtracking典型题，需要加上去重条件
*/

class Solution {
public:
    void mysubsets(vector<vector<int>>& res, vector<int> nums, vector<int> subset, int begin, int end, int n) {
        if(0 == n) {
            res.push_back(subset);
            return;
        }
        for(int i = begin;i <= end;i ++) {
            if(i > begin && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            mysubsets(res, nums, subset, i + 1, end, n - 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        for(int i = 0;i <= nums.size();i ++) {
            mysubsets(res, nums, subset, 0, nums.size() - 1, i);
        }
        return res;
    }
};
