/*Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].*/

/*
思路：
先二分查找到target，再向左右扩展，返回begin和end
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int left = 0, right = nums.size() - 1, middle;
        while(left <= right) {
            middle = left + (right - left) / 2;
            if(nums[middle] == target) {
                int begin = middle, end = middle;
                while(begin > 0 && nums[begin - 1] == target) -- begin;
                while(end < nums.size() - 1 && nums[end + 1] == target) ++ end;
                ans[0] = begin; ans[1] = end;
                break;
            }
            else if(nums[middle] > target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return ans;
    }
};
