/*Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]*/

/*
思路：
与46.Permutations区别在于不交换与当前位置的值相同的元素并且不交换已交换过的元素
*/

class Solution {
public:
    void mycombination(vector<vector<int>>& res, vector<int>& nums, int begin) {
        if(begin == nums.size()) {
            res.push_back(nums);
            return;
        }
        map<int, bool> Map;
        for(int i = begin;i < nums.size();i ++) {
            if(nums[i] == nums[begin] && i != begin || Map.find(nums[i]) != Map.end()) continue;
            Map[nums[i]] = true;
            swap(nums[i], nums[begin]);
            mycombination(res, nums, begin + 1);
            swap(nums[i], nums[begin]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        mycombination(res, nums, 0);
        return res;
    }
};
