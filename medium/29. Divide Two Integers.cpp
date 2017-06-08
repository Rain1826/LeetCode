/*Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.*/

/*
思路：
位运算实现除法
*/

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        const int MAX_INT = 2147483647;
        const int MIN_INT = -2147483648;
        if (!divisor || (dividend == MIN_INT && divisor == -1))
            return MAX_INT;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        int res = 0;
        while (dvd >= dvs)
        {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1))
            {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res;
    }
};

