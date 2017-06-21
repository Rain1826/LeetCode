/*Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.*/

/*
思路：
荷兰国旗问题，用 begin 和 end 两个指针实现
(1) 若遍历到的位置为1，则说明它一定属于中部，不需要交换，然后current向后移动一个位置
(2) 若遍历到的位置为0，则说明它一定属于前部，于是就和begin位置进行交换，然后current向后移动一个位置，begin也向后移动一个位置（表示前边的已经都排好了）
(3) 若遍历到的位置为2，则说明它一定属于后部，于是就和end位置进行交换，由于交换完毕后current指向的可能是属于后面的，若此时current移动则会导致该位置不能被交换到后部，所以此时current不移动。而是end向前移动一个位置。
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() < 2) return;
        int begin = 0, end = nums.size() - 1;
        int current = 0;
        while(current <= end) {
            if(nums[current] == 0) {
                swap(nums[current ++], nums[begin ++]);
            }
            else if(nums[current] == 2) {
                swap(nums[current], nums[end --]);
            }
            else current ++;
        }
    }
};
