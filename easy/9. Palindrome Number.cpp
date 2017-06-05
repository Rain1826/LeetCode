/*Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.*/

/*
思路：
题目要求只能用O(1)的空间，所以不能考虑把它转化为字符串然后reverse比较的方法。
在提示中也提到了，如果考虑reverse number的方法，可能造成溢出。
那么只能选择分离数字的方法
*/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
        {
            return false;
        }
        int len = log10(x);
        int high, low;
        while(x != 0)
        {
            high = x / pow(10, len);
            low = x % 10;
            if(high != low)
            {
                return false;
            }
            x -= high * pow(10, len);
            x /= 10;
            if(x < 0)   x = -x;
            len -= 2;
        }
        return true;
    }

};
