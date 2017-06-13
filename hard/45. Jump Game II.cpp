/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.*/

/*
思路：
贪心，每次循环更新上次最远位置和当前最远位置
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int lastMax = 0, curMax = 0;
        for(int i = 0;i < nums.size();i ++) {
            if(lastMax >= nums.size() - 1) break;
            //如果当前位置大于上次跳的最远位置
            if(i > lastMax) {
                lastMax = curMax;
                ++ step;
            }
            curMax = max(curMax, i + nums[i]);
        }
        return step;
    }
};
