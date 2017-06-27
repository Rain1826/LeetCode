/*Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)*/

/*
思路：
三个for循环找到所有的数字组合，根据isValid函数确定是否符合要求
*/

class Solution {
public:
    bool isValid(string s) {
        if(s.length() > 3 || s.length() == 0 || (s[0] == '0' && s.length() > 1) || stoi(s) > 255)
            return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        vector<string> ans;
        for(int i = 1;i < 4 && i < len - 2;i ++) {
            for(int j = i + 1;j < i + 4 && j < len - 1;j ++) {
                for(int k = j + 1;k < j + 4 && k < len;k ++) {
                    string s1 = s.substr(0, i), s2 = s.substr(i, j - i), s3 = s.substr(j, k - j), s4 = s.substr(k);
                    if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
                        ans.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                }
            }
        }
        return ans;
    }
};
