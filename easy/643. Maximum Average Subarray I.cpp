/*Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].*/

/*
思路：暴力，两层循环
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size() < k) return 0;
        double maxSum = INT_MIN;
        for(int i = 0;i <= nums.size() - k;i ++) {
            double tmp = 0.0;
            for(int j = 0;j < k;j ++) {
                tmp += nums[i + j];
            }
            maxSum = maxSum > tmp ? maxSum : tmp;
        }
        return maxSum / k;
    }
};
