/*Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

/*
思路：
哈希表map：统计每种字符上一次出现的位置
整形变量pre：记录以前一个字符结尾的最长无重复子串的长度
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.length() == 0) return 0;
        map<char, int> hash;
        hash.insert(pair<char, int>(s[0], 0));
        for(int i = 1; i < s.length(); ++ i)
        {
            hash.insert(pair<char, int>(s[i], -1));
        }
        int pre = 1, maxlength = 1;
        for(int i = 1; i < s.length(); ++ i)
        {
            int pos_a = hash[s[i]];
            int pos_b = i - pre - 1;
            pre = i - max(pos_a, pos_b);
            hash[s[i]] = i;
            maxlength = max(maxlength, pre);
        }
        return maxlength;
    }
};
