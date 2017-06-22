/*Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.*/

/*
思路：
说实话这道题自己做的时候只知道是动态规划，完全不知道怎么做，于是看了Solution里的第一个代码，真的佩服
下面还有一个关于求解子序列的一个模板代码
*/

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        for(auto c : t) freq[c] ++;
        int need = t.length();  // t中剩余的需要匹配的字符数
        int minLen = INT_MAX;   // 最小窗口长度
        int begin = 0, end = 0, head = 0;
        while(end < s.length()) {
            if(freq[s[end ++]] -- > 0) need --;
            while(need == 0) {
                if(end - begin < minLen)
                    minLen = end - (head = begin);
                if(freq[s[begin ++]] ++ == 0) need ++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(head, minLen);
    }
};


class Solution {
public:
    int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
   }
};
