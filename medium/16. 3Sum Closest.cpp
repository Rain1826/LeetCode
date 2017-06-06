/*Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

/*
思路：
先固定一个数，再找另外两个数，更新closestSum
*/

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        if(nums.size() < 3) return -1;
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; ++ i)
        {
            int low = i + 1, high = nums.size() - 1;
            while(low < high)
            {
                int curSum = nums[i] + nums[low] + nums[high];
                if(curSum == target) return target;
                if(abs(target - curSum) < abs(target - closestSum))
                {
                    closestSum = curSum;
                }
                if(curSum > target) -- high;
                else    ++ low;
                
            }
            //找到下一个不同的nums[i]
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) ++ i;
        }
        return closestSum;
    }
};
