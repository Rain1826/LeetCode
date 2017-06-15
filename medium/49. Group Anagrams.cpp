/*Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.*/

/*
思路：
将排序后的字符串在hash中查找，若存在则说明之前已插入结果中，找到之前的下标插入即可，否则创建vector加入res并更新hash
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> hash;
        for(int i = 0;i < strs.size();i ++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            //得到排序后strs[i]在hash的下标
            vector<string>::iterator iter = find(hash.begin(), hash.end(), temp);
            if(iter != hash.end()) {
                int index = iter - hash.begin();
                res[index].push_back(strs[i]);
                continue;
            }
            //在hash中没找到说明是新的字符串，创建vector加入res并更新hash
            vector<string> s(1, strs[i]);
            res.push_back(s);
            hash.push_back(temp);
        }
        return res;
    }
};
