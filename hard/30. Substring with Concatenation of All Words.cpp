/*You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).*/

/*
思路：
通过使用两个hash表，分别存储每个字符串的个数和已发现的每个字符串的个数，依次进行匹配
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.length() == 0 || words.size() == 0) return ans;
        unordered_map<string, int> count;
        for(int i = 0;i < words.size(); ++ i) {
            ++ count[words[i]];
        }
        int n = s.length(), num = words.size(), len = words[0].length();
        for(int i = 0;i < n - num * len + 1; ++ i) {
            unordered_map<string, int> seen;
            int j = 0;
            while(j < num) {
                string word = s.substr(i + j * len, len);
                if(count.find(word) != count.end()) {
                    ++ seen[word];
                    if(seen[word] > count[word]) break;
                }
                else break;
                ++ j;
            }
            if(j == num) ans.push_back(i);
        }
        return ans;
    }
};
