/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]*/

/*
思路：
与3Sum思路类似，将4Sum转换成3Sum问题
*/

class Solution
{
public:
    vector<vector<int> > fourSum(vector<int>& nums,int target)
    {
        vector<vector<int> > ans;
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; ++ i)
        {
            int target_3 = target - nums[i];
            for(int j = i + 1; j < nums.size() - 2; ++ j)
            {
                int target_2 = target_3 - nums[j];
                int low = j + 1, high = nums.size() - 1;
                while(low < high)
                {
                    if(nums[low] + nums[high] > target_2) -- high;
                    else if(nums[low] + nums[high] < target_2) ++ low;
                    else
                    {
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[low]);
                        vec.push_back(nums[high]);
                        ans.push_back(vec);
                        //找到下一个不同的nums[low]
                        while(low < high && nums[low] == vec[2]) ++ low;
                        //找到下一个不同的nums[high]
                        while(low < high && nums[high] == vec[3]) -- high;
                    }
                }
                //找到下一个不同的nums[j]
                while(j + 1 < nums.size() && nums[j + 1] == nums[j]) ++ j;
            }
            //找到下一个不同的nums[i]
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) ++ i;
        }
        return ans;
    }
};
