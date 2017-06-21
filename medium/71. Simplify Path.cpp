/*Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"*/

/*
思路：
自定义一个split函数将'/'间的字符串分割并加入到一个vector中，之后再根据具体内容进行处理
'./'表示当前目录，'../'表示上一级目录
*/

class Solution {
public:
    vector<string> split(string str, char c) {
        vector<string> res;
        int index = -1;
        while(!str.empty() && (index = str.find(c, 0)) != -1) {
            res.push_back(str.substr(0, index));
            str = str.substr(index + 1);
        }
        if(!str.empty()) res.push_back(str);
        return res;
    }
    string simplifyPath(string path) {
        vector<string> vec = split(path, '/');
        vector<string> ans;
        string res = "";
        for(int i = 0;i < vec.size();i ++) {
            if(vec[i] == "" || vec[i] == ".") continue;
            if(vec[i] == ".." && !ans.empty())  ans.pop_back();
            else if(vec[i] != "..") ans.push_back(vec[i]);
        }
        for(int i = 0;i < ans.size();i ++) {
            res += "/" + ans[i];
        }
        return res.empty() ? "/" : res;
    }
};
