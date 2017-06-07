/*Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.(手机按键)

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return vector<string>();
        }
        string str[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        ans.push_back("");
        for(int i = 0;i < digits.size(); ++ i) {
            string tempstr = str[digits[i] - '0'];
            vector<string> tempans;
            for(int j = 0;j < tempstr.size(); ++ j) {
                for(int k = 0;k < ans.size(); ++ k) {
                    tempans.push_back(ans[k] + tempstr[j]);
                }
            }
            ans = tempans;
        }
        return ans;
    }
};
