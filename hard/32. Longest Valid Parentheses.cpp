/*Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.*/

/*
思路：
创建一个栈存储所有不匹配的括号索引，索引之间相差的最大值就是最长匹配长度
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> Stack;
        for(int i = 0;i < s.length(); ++ i) {
            if(s[i] == '(') Stack.push(i);
            else if(!Stack.empty() && s[Stack.top()] == '(')   Stack.pop();
            else    Stack.push(i);
        }
        if(Stack.empty())   return s.length();
        int longest = 0;
        int begin = 0, end = s.length();
        while(!Stack.empty()) {
            begin = Stack.top();    Stack.pop();
            longest = max(longest, end - begin - 1);
            end = begin;
        }
        longest = max(longest, begin);
        return longest;
    }
};
