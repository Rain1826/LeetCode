/*Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.*/

/*
思路：
该题题干不是很明确，只能根据用例来理解什么样的字符串才是符合题意的，本题关键在于几个标志位的设立，将字符串分为几个部分
*/

class Solution
{
public:
    string trim(string s)
    {
        int i=0;
        while(s[i]==' ') i ++;      //开头处为空格或者Tab，则跳过
        s=s.substr(i);
        i=s.size()-1;
        while(s[i]==' ') i --;      //结尾处为空格或者Tab，则跳过
        s=s.substr(0,i+1);
        return s;
    }
    bool isNumber(string s)
    {
        s = trim(s);

        bool pointSeen = false;
        bool eSeen = false;
        bool partOne = false;
        bool partTwo = false;

        for(int i = 0; i < s.length(); i ++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                if(!eSeen)
                    partOne = true;
                else
                    partTwo = true;
            }
            else if(s[i] == '.')
            {
                if(pointSeen || eSeen)
                    return false;
                pointSeen = true;
            }
            else if(s[i] == 'e')
            {
                if(eSeen || !partOne)
                    return false;
                eSeen = true;
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                if(i != 0 && s[i - 1] != 'e')
                    return false;
            }
            else    return false;
        }
        if(!partOne)
            return false;
        else if(eSeen && !partTwo)
            return false;
        else
            return true;
    }
};
