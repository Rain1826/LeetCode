/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.*/

/*
思路：
模拟乘法手算过程，先将数字都逆序方便操作，num1的i位和num2的j位相乘是第i+j位，在之前要先根据进位更新i+j+1位
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        string res(500, '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i = 0;i < num1.length();i ++) {
            for(int j = 0;j < num2.length();j ++) {
                int temp = (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] = res[i + j + 1] - '0' + (res[i + j] - '0' + temp) / 10 + '0';//进位
                res[i + j] = (res[i + j] - '0' + temp) % 10 + '0';//更新i+j位置的值
            }
        }
        reverse(res.begin(), res.end());
        //最终结果为0
        if(res.find_first_not_of('0') == string::npos)  
            res = '0';  
        else//删除所有前导0
            res.erase(res.begin(), res.begin() + res.find_first_not_of('0')); 
        return res;
    }
};
