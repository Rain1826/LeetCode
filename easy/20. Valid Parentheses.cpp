/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.*/

/*
思路：
左侧括号入栈，遇到右侧括号就匹配，最后判断栈是否为空
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        for(int i = 0;i < s.size(); ++ i) {
            switch(s[i]) {
                case '(':   case '{':   case '[':   {
                    Stack.push(s[i]);   
                    break;
                }
                case ')':   {
                    if(Stack.empty() || Stack.top() != '(') return false;
                    else   Stack.pop();
                    break;
                }
                case '}':   {
                    if(Stack.empty() || Stack.top() != '{') return false;
                    else   Stack.pop();
                    break;
                }
                case ']':   {
                    if(Stack.empty() || Stack.top() != '[') return false;
                    else   Stack.pop();
                    break;
                }
                default:    break;
            }
        }
        return Stack.empty();
    }
};
