/*The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.*/

/*
思路：
迭代的思想，假设算出了n=2时是00,01,11,10
则n=3时，结果为(000,001,011,010 ) (110,111,101,100)，在保留n=2的同时，再在前面全部填上1
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1, 0);
        for(int i = 0;i < n;i ++) {
            for(int j = ans.size() - 1;j >= 0;j --) {
                ans.push_back(ans[j] | 1<<i);
            }
        }
        return ans;
    }
};
