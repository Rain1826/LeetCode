/*You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.*/

/*
思路：
a.因为两种跳法，1阶或者2阶，那么假定第一次跳的是一阶，那么剩下的是n-1个台阶，跳法是f(n-1); 
b.假定第一次跳的是2阶，那么剩下的是n-2个台阶，跳法是f(n-2) 
c.由a、b假设可以得出总跳法为: f(n) = f(n-1) + f(n-2) 
d.然后通过实际的情况可以得出：只有一阶的时候 f(1) = 1 ,只有两阶的时候可以有 f(2) = 2 
e.可以发现最终得出的是一个斐波那契数列。
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2) {
            return n;
        }
        vector<int> ans(n + 1, 0);
        ans[1] = 1;
        ans[2] = 2;
        for(int i = 3;i <= n;i ++) {
            ans[i] = ans[i - 1] + ans[i - 2];
        }
        return ans[n];
    }
};
