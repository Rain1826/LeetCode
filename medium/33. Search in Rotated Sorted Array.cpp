/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.*/

/*
思路：
二分法查找：循环数组有一边是有序的，首先先判断哪一边有序（通过将当前mid点与最左边节点比较），然后查看是否在有序边上
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())    return -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int middle = left + (right - left) / 2;
            if(nums[middle] == target) {
                return middle;
            }
            if(nums[left] <= nums[middle]) {
                if(nums[left] <= target && target <= nums[middle]) {
                    right = middle - 1;
                }
                else {
                    left = middle + 1;
                }    
            }
            else {
                if(nums[middle] <= target && target <= nums[right]) {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                }
            }
        }
        return -1;
    }
};
