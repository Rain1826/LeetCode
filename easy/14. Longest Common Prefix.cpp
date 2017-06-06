/*Write a function to find the longest common prefix string amongst an array of strings.*/

/*
思路：
找string数组的最长前缀子串，每次循环遍历，都相等就加入到com，否则跳出循环返回
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1)    return strs[0];
        string com = "";
        int index = 0;
        while(true){
            char temp = strs[0][index];
            for(int i = 1;i < strs.size(); ++ i){
                if(temp != strs[i][index])  return com;
            }
            com += temp;
            ++ index;
        }
    }
};
