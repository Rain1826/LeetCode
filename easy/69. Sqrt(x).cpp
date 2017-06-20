/*Implement int sqrt(int x).

Compute and return the square root of x.*/

/*
思路：二分法求平方根
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) {
            return x;
        }
        int left = 1, right = INT_MAX;
        while(true) {
            int mid = left + (right - left) / 2;
            if(mid > x / mid) {
                right = mid - 1;
            }
            else {
                // 此时 mid ^ 2 <= x
                if((mid + 1) > x / (mid + 1)) {
                    return mid;
                }
                left = mid + 1;
            }
        }
    }
};
