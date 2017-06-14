/*Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]*/

/*
思路：
直接在原数组上交换当前位置和其余位置，进行递归
*/

class Solution {
public:
    void mycombination(vector<vector<int>>& res, vector<int>& nums, int begin) {
        if(begin == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i = begin;i < nums.size();i ++) {
            swap(nums[i], nums[begin]);
            mycombination(res, nums, begin + 1);
            swap(nums[i], nums[begin]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        mycombination(res, nums, 0);
        return res;
    }
};
