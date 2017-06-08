/*Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/

/*
思路：
简单模式匹配
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_1 = haystack.length();
        int len_2 = needle.length();
        if(len_1 < len_2) return -1;
        int index_1 = 0, index_2 = 0;
        while(index_1 < len_1 && index_2 < len_2) {
            if(haystack[index_1] == needle[index_2]) {
                ++ index_1; ++ index_2;
            }
            else {
                index_1 = index_1 - index_2 + 1;
                index_2 = 0;
            }
        }
        if(index_2 == len_2)    return index_1 - index_2;
        else    return -1;
    }
};
