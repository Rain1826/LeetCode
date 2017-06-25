/*Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.*/

/*
思路：
同84. Largest Rectangle in Histogram类似，只是这是二维版本的，因此将矩阵每一行作为x轴，更新每个位置的高度，求出Largest Rectangle
找出所有Largest Rectangle的最大值即可
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())  return 0;
        int maxRec = 0;
        vector<int> height(matrix[0].size(), 0);
        for(int i = 0;i < matrix.size();i ++) {
            for(int j = 0;j < matrix[0].size();j ++) {
                if(matrix[i][j] == '1') ++ height[j];
                else    height[j] = 0;
            }
            maxRec = max(maxRec, largestRectangleArea(height));
        }
        return maxRec;
    }
};
