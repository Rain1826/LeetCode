/*Implement pow(x, n).*/

/*
思路：快速幂
*/

class Solution {
public:
    double myPow(double base, int n) {
        long long p = abs((long long)n);
        double ans = 1.0;
        while(p) {
            if(p & 1)
                ans *= base;
            base *= base;
            p >>= 1;
        }
        return n >= 0 ? ans : 1 / ans;
    }
};
