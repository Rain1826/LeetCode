/*Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.*/

/*
思路：
1.数字前面有空格，如s="    123456"，空格需舍弃。
2.数字前出现了不必要或多于的字符导致数字认证错误，输出0。如s="   b1234"，s="  ++1233", s=" +-1121"。
3.数字中出现了不必要的字符，返回字符前的数字。如s="   12a1"， s=" 123  123"。
4.数字越界，超过了范围（-2147483648--2147483647)，分别返回-2147483648和2147483647。
*/

class Solution
{
public:
    int myAtoi(string str)
    {
        if(str == "")
            return 0;
        int i = 0;
        long long res = 0;
        while(str[i] != '\0' && str[i] == ' ')
        {
            i ++;//舍弃前面空格
        }
        int flag = 1;
        if(str[i] == '-')//确定正负
        {
            flag = -1;
            i ++;
        }
        else if(str[i] == '+')
        {
            i ++;
        }
        while(str[i] != '\0')
        {
            if(str[i] >= '0' &&str[i] <= '9')
            {
                res = res*10 + str[i] - '0';
                if(res > INT_MAX)
                {
                    if(flag == 1)
                        return INT_MAX;
                    else
                        return INT_MIN;
                }
                i ++;
            }
            else break;
        }
        res = flag * res;
        return (int)res;
    }
};
