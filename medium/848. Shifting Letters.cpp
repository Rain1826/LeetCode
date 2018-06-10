/*We have a string S of lowercase letters, and an integer array shifts.

Call the shift of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a'). 

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.

Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x times.

Return the final string after all such shifts to S are applied.

Example 1:

Input: S = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: 
We start with "abc".
After shifting the first 1 letters of S by 3, we have "dbc".
After shifting the first 2 letters of S by 5, we have "igc".
After shifting the first 3 letters of S by 9, we have "rpl", the answer.
Note:

1 <= S.length = shifts.length <= 20000
0 <= shifts[i] <= 10 ^ 9*/

/*
思路：
由题意可知，字符串每个字符的偏移量由后向前分别为shifts数组由后向前累加的值，由此只需每次更新delta即可
注：要在加delta之前判断是否越界，否则超过ascii范围则判断失效
*/

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        string res = S;
        int delta = 0, index = shifts.size() - 1;
        for(int i = S.length() - 1;i >= 0;i --) {
            delta = (delta + shifts[index --]) % 26;
            if(res[i] + delta > 'z') {
                res[i] += delta - 26;
            } else {
                res[i] += delta;
            }
        }
        return res;
    }
};
