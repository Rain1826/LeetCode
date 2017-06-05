/*Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.*/

/*
思路：关键在于判断溢出
*/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        const int MAX_INT = 2147483647;
        while(x != 0){
            if(abs(res) > MAX_INT/10){
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
