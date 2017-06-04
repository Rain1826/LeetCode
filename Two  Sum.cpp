/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for(int i = 0;i < nums.size(); ++ i) {
            hash.insert(pair<int, int>(nums[i], i));
        }
        vector<int> ans;
        map<int, int>::iterator iter;
        for(int i = 0;i < nums.size(); ++ i) {
            if((iter = hash.find(target - nums[i])) != hash.end()) {
                if(iter->second == i) continue; //要排除两个相同索引
                ans.push_back(i);
                ans.push_back(iter->second);
                break;
            }
        }
        return ans;
    }
};
