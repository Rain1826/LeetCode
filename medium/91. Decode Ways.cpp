/*A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.*/

/*
思路：
动态规划，dp[i]表示前i个字符能满足多少种组合
*/

class Solution {
public:
    bool isValid(char c) {
        return c >= '1' && c <= '9';
    }
    bool isValid(char a, char b) {
        return a == '1' || a == '2' && b <= '6';
    }
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0 || s[0] == '0')   return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2;i <= n;i ++) {
            //单独一个数字
            if(isValid(s[i - 1])) {
                dp[i] += dp[i - 1];
            } 
            //两个数字合并
            if(isValid(s[i - 2], s[i - 1])) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
