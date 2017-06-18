/*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.*/

/*
思路：扫描法
例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5， 
那么最大的子数组为3, 10, -4, 7, 2， 
因此输出为该子数组的和18。 
 
所有的东西都在以下俩行， 
即： 
curSum ：  0  1  -1  3  13   9  16  18  13   
maxSum ：  0  1   1  3  13  13  16  18  18 
   
其实算法很简单，当前面的几个数，加起来后，curSum < 0后， 
把 curSum 重新赋值，置为下一个元素，curSum = nums[i]。 
当 curSum > maxSum，则更新maxSum = curSum; 
若 curSum < maxSum，则 maxSum 保持原值，不更新...
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() < 2) return nums[0];
        int curSum = nums[0], maxSum = nums[0];
        for(int i = 1;i < nums.size();i ++) {
            if(curSum < 0) {
                curSum = nums[i];
            }
            else {
                curSum += nums[i];
            }
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
