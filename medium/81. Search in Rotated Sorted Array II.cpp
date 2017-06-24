/*Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.*/

/*
思路：
二分法，注意等号
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())    return false;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int middle = left + (right - left) / 2;
            if(nums[middle] == target) {
                return true;
            }
            if(nums[middle] > nums[left]) {
                if(target < nums[middle] && target >= nums[left])   right = middle - 1;
                else    left = middle + 1;
            }
            else if(nums[middle] < nums[left]) {
                if(target > nums[middle] && target <= nums[right])   left = middle + 1;
                else    right = middle - 1;
            }
            else    left ++;
        }
        return false;
    }
};
