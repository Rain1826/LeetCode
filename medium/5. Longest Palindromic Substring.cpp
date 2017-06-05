/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example:
Input: "cbbd"
Output: "bb"*/

/*
思路：
Manacher算法：
两个辅助变量id和mx，id表示最大回文子串的中心，mx为id+p[id](p[i]表示以s[i]为中心的回文子串长度)，即最大回文子串的边界。
可得出重要结论：如果 mx > i，那么p[i] >= min(p[2*id - i], mx - i)
预处理：
如：将字符串 S = "abc" 变为 S = "$#a#b#c#"
*/

class Solution
{
public:
    string Preprocessing_Str(string s)
    {
        string str = "$";
        for(int i = 0; i < s.length(); ++ i)
        {
            str += "#";
            str += s[i];
        }
        str += "#";
        return str;
    }

    string longestPalindrome(string s)
    {
        string str = Preprocessing_Str(s);
        int id, mx = 0, maxLength = 0;
        string ans = "";
        int *p = new int[str.length()];
        memset(p, 0, str.length());
        for(int i = 1; i < str.length(); ++ i)
        {
            //mx > i时，p[i] >= min(p[2 * id - 1], mx - i)
            if(mx > i)
            {
                p[i] = min(p[2 * id - 1], mx - i);
            }
            else
            {
                //mx <= i时，无法对p[i]做更多假设，直接让p[i] = 1
                p[i] = 1;
            }
            //继续向两侧扩展比较
            while(str[i + p[i]] == str[i - p[i]])
            {
                ++ p[i];
            }
            //更新最长回文子串的中心和边界
            if(p[i] - 1 > maxLength)
            {
                mx = p[i] + i;
                id = i;
                maxLength = p[i] - 1;
            }
        }
        //要截取的字符串长度为 (id + p[id] - 1) - (id - p[id] + 1) = 2 * p[id] - 2
        ans = str.substr(id - p[id] + 1, 2 * p[id] - 2);
        while(ans.find("#") != -1)
            ans = ans.replace(ans.find("#"), 1, "");
        return ans;
    }
};
