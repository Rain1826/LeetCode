/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.*/

/*
思路：
设置左右两个标记，由低的一侧向中间移动，同时更新左侧最大值和右侧最大值。
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        int leftmax = 0, rightmax = 0;
        while(left <= right) {
            if(height[left] <= height[right]) {
                if(height[left] >= leftmax)  leftmax = height[left];
                else    res += leftmax - height[left];
                left ++;
            }
            else {
                if(height[right] >= rightmax)   rightmax = height[right];
                else    res += rightmax - height[right];
                right --;
            }
        }
        return res;
    }
};
