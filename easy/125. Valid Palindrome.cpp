/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false*/

/*
思路：
先将原字符串做处理，去掉除字母、数字的字符
再根据left、right判断是否是回文
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.length())  return true;
        string str;
        for(int i = 0;i < s.length(); i ++) {
            if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')) {
                str += s[i];
            }
            else if(s[i] >= 'A' && s[i] <= 'Z') {
                str += s[i] + 32;
            }
        }
        int left = -1, right = str.length();
        while(++left < --right) {
            if(str[left] != str[right])
                return false;
        }
        return true;
    }
};
