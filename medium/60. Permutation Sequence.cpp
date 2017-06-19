/*The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.*/

/*
思路：
比如当前长度是n，我们知道每个相同的起始元素对应(n-1)!个permutation，也就是(n-1)!个permutation后会换一个起始元素。
因此，只要当前的k进行(n-1)!取余，得到的数字就是当前剩余数组的index，如此就可以得到对应的元素。如此递推直到数组中没有元素结束。
实现中我们要维护一个数组来记录当前的元素，每次得到一个元素加入结果数组，然后从剩余数组中移除。
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        vector<char> vec;
        for(int i = 1;i <= n;i ++) {
            str += (i + '0');
            vec.push_back(i + '0');
        }
        int fac = 1, round = n - 1;
        for(int i = 2;i < n;i ++) {
            fac *= i;
        }
        string res = "";
        k --;
        while(round >= 0) {
            int index = k  / fac;
            k %= fac;
            res += vec[index];
            vec.erase(vec.begin() + index);
            if(round > 0)
                fac /= round;
            round --;
        }
        return res;
    }
};
