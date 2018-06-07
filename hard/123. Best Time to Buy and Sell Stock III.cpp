/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.*/

/*
思路：
遍历数组，以每一个数作为分割线分别求左右两边各一次交易最大获利，即[Best Time to Buy and Sell Stock I]
具体实现，两次分别从左向右和从右向左遍历数组，DP求解
最后遍历一遍，左右最大相加，不断更新维护res
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        vector<int> left(prices.size()), right(prices.size());
        // 从左向右
        int min_left = prices[0];
        for(int i = 1;i < prices.size(); i ++) {
            min_left = min(min_left, prices[i]);
            left[i] = max(left[i - 1], prices[i] - min_left);
        }
        // 从右向左
        int max_right = prices[prices.size() - 1];
        for(int i = prices.size() - 2;i >= 0; i --) {
            max_right = max(max_right, prices[i]);
            right[i] = max(right[i + 1], max_right - prices[i]);
        }
        int res = left[0] + right[0];
        for(int i = 1; i < prices.size(); i ++) {
            res = max(res, left[i] + right[i]);
        }
        return res;
    }
};
