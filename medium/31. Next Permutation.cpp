/*Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1*/

/*
思路：
从后向前找，寻找一个前面的数小于当前数的位置i，则i-1位置是需要被交换的位置，在i到数组结束找到一个刚刚比i-1位置大的数，交换，结束
若未找到，则升序排序整个数组
*/

class Solution {
public:
    inline void swap(int &x, int &y) {
        x ^= y;
        y ^= x;
        x ^= y;
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)    return;
        for(int i = nums.size() - 1; i > 0; -- i) {
            if(nums[i] > nums[i - 1]) {
                sort(nums.begin() + i, nums.end());
                for(int j = i; j < nums.size(); ++ j) {
                    if(nums[j] > nums[i - 1]){
                        swap(nums[i - 1], nums[j]);
                        return;
                    }
                }
                swap(nums[i - 1], nums[i]);
                return;
            }
        }
        //原顺序已经是最大，则按升序排列
        sort(nums.begin(), nums.end());
    }
};
