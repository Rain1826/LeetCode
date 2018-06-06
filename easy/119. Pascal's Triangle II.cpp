/*Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?*/

/*
思路：
使用两个变量存储每次需要相加的值，循环更新结果vector中对应位置的值
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 2)
            return vector<int>(rowIndex + 1, 1);
        vector<int> res(rowIndex + 1, 1);
        int pre = 1, next = 1;
        for(int i = 2;i <= rowIndex;i ++) {
            for(int j = 1;j < i;j ++) {
                res[j] = pre + next;
                pre = next;
                next = res[j + 1];
            }
            pre = res[0];
            next = res[1];
        }
        return res;
    }
};
