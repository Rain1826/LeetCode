/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".*/

/*
思路：
题意就是把原字符串按|/|/|排列，再按行组合输出
所以只要建立一个保存numRows个字符串的数组循环存入即可
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)    return s;
        string res[numRows];
        int i = 0;
        while(i < s.length()) {
            for(int j = 0;i < s.length() && j < numRows; ++ j){
                res[j] += s[i ++];
            }
            for(int j = numRows - 2;i < s.length() && j > 0; -- j){
                res[j] += s[i ++];
            }
        }
        string str = "";
        for(int i = 0;i < numRows; ++ i){
            str += res[i];
        }
        return str;
    }
};
