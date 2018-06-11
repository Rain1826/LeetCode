/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.*/

/*
思路：
在遍历nums容器时，对每个值进行左右扩展，找到包含当前位置元素的最长连续序列
同时需要两个set集合对已处理元素和未处理元素进行标记
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> unused, used;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++ iter) {
            unused.insert(*iter);
        }
        int max_length = 1;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++ iter) {
            if(used.find(*iter) != used.end())
                continue;
            int left = *iter - 1, right = *iter + 1, current_length = 1;
            set<int>::iterator it;
            while((it = unused.find(left)) != unused.end()) {
                unused.erase(it);
                used.insert(*iter);
                ++ current_length;
                -- left;
            }
            while((it = unused.find(right)) != unused.end()) {
                unused.erase(it);
                used.insert(*iter);
                ++ current_length;
                ++ right;
            }
            max_length = max(max_length, current_length);
        }
        return max_length;
    }
};
