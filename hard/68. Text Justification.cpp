/*Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.*/

/*
思路：暴力..无算法
*/

class Solution {
public:
    void addSpace(string& str, int maxWidth, bool end) {
        // str 中原有的空格数量 numOfspace
        int numOfspace = 0;
        for(int i = 0;i < str.length();i ++) {
            if(str[i] == ' ')   ++ numOfspace;
        }
        // str 要插入的空格数量 insertNum
        int insertNum = maxWidth - str.length();
        if(numOfspace == 0 || end) { // 说明只有一个单词或到了最后一行，直接在后面加空格
            for(int i = 0;i < insertNum;i ++)
                str += " ";
            return;
        }
        int num = insertNum / numOfspace;
        insertNum %= numOfspace;
        string insertSpace = "";
        while(num --) insertSpace += " ";
        for(int i = 0;i < str.length();i ++) {
            if(str[i] == ' ') {
                str.insert(i, insertSpace);
                while(str[i] == ' ') i ++;
            }
        }
        int index = 0;
        for(int i = 0;i < insertNum;i ++, index ++) {
            while(str[index] != ' ') index ++;
            str.insert(index ++, " ");
        }
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        if(words.empty()) {
            return ans;
        }
        string str = words[0];
        for(int i = 1;i < words.size();i ++) {
            if(str.length() + words[i].length() < maxWidth) {
                str += " " + words[i];
            }
            else {
                ans.push_back(str);
                str = words[i];
            }
        }
        ans.push_back(str);
        for(int i = 0;i < ans.size() - 1;i ++) {
            addSpace(ans[i], maxWidth, false);
        }
        addSpace(ans[ans.size() - 1], maxWidth, true);
        return ans;
    }
};
