/*Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.*/

/*
思路：
位运算实现除法
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        const int MAX_INT = 2147483647;
        const int MIN_INT = -2147483648;
        if(divisor == 0)    return MAX_INT;
        if(divisor == 1)    return dividend;
        if(divisor == -1) {
            if(dividend == MIN_INT) return MAX_INT;
            else    return -dividend;
        }
        bool flag = ((dividend < 0) ^ (divisor < 0)) ? false : true;
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            ans += multiple;
        }
        return flag ? ans : -ans;
    }
};
