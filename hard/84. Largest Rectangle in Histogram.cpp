/*Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.*/

/*
思路：参考https://segmentfault.com/a/1190000007409249
用栈来模拟，遍历heights数组，如果大于栈顶元素，就push进去；否则，持续弹栈来计算从栈顶点到降序点的矩阵大小。然后将这一部分全部替换为降序点的值，即做到了整体依然是有序非降的。
整个过程中，即把所有的局部最大矩阵计算过了，又在宽度范围内保留了全部的场景。
举例，2，1，5，6，3的场景。
先加入一个0，方便最后可以全部弹栈出来。变成：2，1，5，6，3，0.
2进栈，1比栈顶小，对2进行出栈，area = 2；
2被替换为1进栈，1继续进栈，这是栈为1，1；
5，6都是非降的，继续进栈，栈为1，1，5，6；
遇到3，是一个降序点；开始弹栈，6出栈，对应area=61； 5出栈对应area=52；下一个1比3小，不需要弹栈。然后将5、6的弹栈后的空位压栈为3，这是栈为1，1，3，3，3；
下一步遇到0，开始依次出栈，得到area=31，32，33，14，1*5。
遍历结束。整个过程中max的area为10.

在整个过程中，将每一个点作为起点，到各个波峰最大的几个矩阵都计算过一次，即保证了每个点作为起点的最大矩阵可能性都试探过。
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<int> stack(1,0);
        int maxArea = 0;
        for(int i = 0;i < heights.size();i ++) {
            if(heights[i] >= stack.back()) {
                stack.push_back(heights[i]);
                continue;
            }
            int width = 1;
            int j = stack.size() - 1;
            while(j >= 0 && stack[j] > heights[i]) {
                maxArea = max(maxArea, stack[j] * (width ++));
                stack[j --] = heights[i];
            }
            stack.push_back(heights[i]);
        }
        return maxArea;
    }
};
