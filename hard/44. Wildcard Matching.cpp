/*Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false*/

/*
思路：
非递归进行回溯，即，在s和p右移的时候，当p的当前字符为'*'时，用s_ptr和p_ptr两个指针记录一下当前位置；
当没有匹配的时候，s和p回溯到s_ptr和p_ptr位置的下一位置。就这样直到s到达字符串尾部。
注意一下，当s到达尾部的时候，p可能没有到达尾部。此时需要检测p的剩余字符是否全为'*'：如果是，返回true；否则，返回false。
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        const char *S = s.c_str(), *P = p.c_str();
        const char *s_ptr = S, *p_ptr = NULL;
        while(*S != '\0') {
            if(*P == '?' || *P == *S) {
                ++ P;   ++ S;
            }
            else if(*P == '*') {
                s_ptr = S;
                p_ptr = P ++;
            }
            else if(p_ptr != NULL) {
                S = ++ s_ptr;
                P = p_ptr + 1;
            }
            else    return false;
        }
        while(*P != '\0') {
            if(*P != '*')   return false;
            P ++;
        }
        return true;
    }
};
