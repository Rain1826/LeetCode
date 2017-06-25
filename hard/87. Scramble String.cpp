/*Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.*/

/*
思路：
这道题的要求是判断两个字符串是否是Scramble String。
如果两个字符串是Scramble String，则其长度必然相等。
而且，在某位置切开s1，则s1左侧与s2左侧相同数量的子串为Scramble String，并且s1右侧与s2右侧相同数量的子串为Scramble String；
或者s1左侧与s2右侧相同数量的子串为Scramble String，并且s1右侧与s2左侧相同数量的子串为Scramble String。
下面是两种方法：递归、动态规划
两者依据的都是上面的思路
*/

//递归法
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)    return true;
        if(s1.length() != s2.length())  return false;
        int len = s1.length();
        int cnt[26] = {0};//剪枝，若两字符串字符个数不完全相同返回false
        for(int i = 0;i < len;i ++) cnt[s1[i] - 'a'] ++;
        for(int j = 0;j < len;j ++) cnt[s2[j] - 'a'] --;
        for(int k = 0;k < 26;k ++)  if(cnt[k] != 0) return false;
        for(int i = 1;i < len;i ++) {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
                return true;
        }
        return false;
    }
};

//动态规划法
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length())  return false;
        int length = s1.length();
        //dp[i][j][len]表示是以i和j分别为s1和s2起点的长度为len的字符串是不是互为Scramble String
        vector<vector<vector<bool>>> dp(length, vector<vector<bool>>(length, vector<bool>(length + 1, false)));
        for(int i = 0;i < length;i ++) {
            for(int j = 0;j < length;j ++) {
                dp[i][j][1] = s1[i] == s2[j];
            }
        }
        for(int len = 2;len <= length; len ++) {
            for(int i = 0;i < length - len + 1;i ++) {
                for(int j = 0;j < length - len + 1;j ++) {
                    //k来枚举分割的位置
                    for(int k = 1;k < len;k ++) {
                        dp[i][j][len] = dp[i][j][len] ||
                                        dp[i][j][k] && dp[i + k][j + k][len - k] ||
                                        dp[i][j + len - k][k] && dp[i + k][j][len - k];
                    }
                }
            }
        }
        return dp[0][0][length];
    }
};
