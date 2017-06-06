/*Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.*/

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> Map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for(int i = 0; i < s.length() - 1; i ++)
        {
            if(Map[s[i]] < Map[s[i+1]])
                sum -= Map[s[i]];
            else
                sum += Map[s[i]];
        }
        sum += Map[s[s.length() - 1]];
        return sum;
    }
};
