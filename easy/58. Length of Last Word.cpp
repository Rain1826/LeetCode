/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.*/

/*
思路：
求一个字符串最后一个单词的长度，先去除后面的' ',再向前遍历知道遇到' '
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int index = s.length() - 1;
        while(index >= 0 && s[index] == ' ') {
            -- index;
        }
        while(index >= 0 && s[index] != ' ') {
            ++ ans; -- index;
        }
        return ans;
    }
};
