/*Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4*/

/*
思路：
使用一个set将出现2次的数字去重，最后剩下的就是结果
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> tmp;
        for (vector<int>::iterator iter=nums.begin(); iter!=nums.end(); iter ++) {
            if(tmp.find(*iter) == tmp.end()) {
                tmp.insert(*iter);
            } else {
                tmp.erase(*iter);
            }
        }
        return *tmp.begin();
    }
};
