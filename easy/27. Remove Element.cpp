/*Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.*/

/*
思路：
题意是返回数组中不等以val的个数，并将数组前n个元素变为最后剩余的元素
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = 0;
        for(int i = 0;i < nums.size(); ++ i) {
            if(nums[i] == val) {
                ++ n;
            }
            else {
                nums[i - n] = nums[i];
            }
        }
        return nums.size() - n;
    }
};
