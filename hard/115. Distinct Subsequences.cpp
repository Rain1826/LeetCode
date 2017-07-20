/*Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.*/

/*
思路：
题目给定两个字符串，选择只可以用删除字符的方法从第一个字符串变换到第二个字符串，求出一共有多少种变换方法；
定义二维数组dp[i][j]为字符串s(0,i)变换到t(0,j)的变换方法。
如果S[i]==T[j]，那么dp[i][j] = dp[i-1][j-1] + dp[i-1][j]。意思是：如果当前S[i]==T[j]，那么当前这个字母即可以保留也可以抛弃，
所以变换方法等于保留这个字母的变换方法加上不用这个字母的变换方法。
如果S[i]!=T[i]，那么dp[i][j] = dp[i-1][j]，意思是如果当前字符不等，那么就只能抛弃当前这个字符。
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.empty())   return t.empty();
        if(s.length() < t.length()) return 0;
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 0;i <= s.size();i ++) {
            dp[i][0] = 1;
        }
        for(int i = 1;i <= s.size();i ++) {
            for(int j = 1;j <= t.size();j ++) {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};
