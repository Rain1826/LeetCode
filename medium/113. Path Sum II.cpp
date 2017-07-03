/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]*/

/*
思路：backtracking
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void myPath(TreeNode* root, vector<vector<int>>& ans, vector<int> path, int sum) {
        if(root == NULL) return;
        path.push_back(root->val);
        if(root->val == sum && root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }
        if(root->left != NULL) {
            myPath(root->left, ans, path, sum - root->val);
        }
        if(root->right != NULL) {
            myPath(root->right, ans, path, sum - root->val);
        }   
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        myPath(root, ans, path, sum);
        return ans;
    }
};
