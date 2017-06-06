/*Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true*/

/*
思路：
 * 表示前一个字符出现0次或以上，因此 * 不能在模式串首位； . 表示任意一个字符
  当包含 * 时，返回p后移两位（*代表0次）或s后移一位（两串当前字符匹配）
  当不包含 * 时，则直接匹配当前字符，返回两串均后移一位
*/

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())    return s.empty();
        if ('*' == p[0])    return false;
        if ('*' == p[1])
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};
