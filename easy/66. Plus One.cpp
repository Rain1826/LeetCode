/*Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.*/

/*
思路：
大数加法，判断进位
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 从后往前，碰到第一个不是9的就对其加1，然后返回即可
        for(int i = digits.size() - 1;i >= 0;i --) {
            if(digits[i] != 9) {
                digits[i] ++;
                return digits;
            }
            digits[i] = 0;
        }
        // 在最高位前面添一个1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
