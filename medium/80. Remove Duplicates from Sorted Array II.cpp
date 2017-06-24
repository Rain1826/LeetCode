/*Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.*/

/*
思路：
同easy中的Remove Duplicates from Sorted Array类似，用数组的前一部分来存储，只是添加了标志位来判断是否已经加入了两个相同元素
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool repeat = false;    //判断是否已经遍历过重复元素
        if(nums.size() <= 2) {
            return nums.size();
        }
        int id = 1;
        for(int i = 1;i < nums.size();i ++) {
            if(nums[i] == nums[i - 1]) {
                if(!repeat) {
                    repeat = true;
                    nums[id ++] = nums[i];
                }
                else continue;
            }
            else {
                repeat = false;
                nums[id ++] = nums[i];
            }
        }
        return id;
    }
};
