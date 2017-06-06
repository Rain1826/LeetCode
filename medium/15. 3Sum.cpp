/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/

/*
思路：
先固定一个数，在通过两侧下标向中间查找target
注意：去重
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size() - 2; ++ i) {
            int target = -nums[i];
            int low = i + 1, high = nums.size() - 1;
            while(low < high) {
                if(nums[low] + nums[high] > target) -- high;
                else if(nums[low] + nums[high] < target) ++ low;
                else {
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[low]);
                    vec.push_back(nums[high]);
                    ans.push_back(vec);
                    //找到下一个不同的nums[low]
                    while(low < high && nums[low] == vec[1]) ++ low;
                    //找到下一个不同的nums[high]
                    while(low < high && nums[high] == vec[2]) -- high;
                }
            }
            //找到下一个不同的nums[i]
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) ++ i;
        }
        return ans;
    }
};
