/*Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42*/

/*
思路：
递归计算每个结点作为路径根结点时的最大值，更新res
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
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        depth(root, res);
        return res;
    }
private:
    int depth(TreeNode* root, int& res) {
        if(!root)   return 0;
        int left = depth(root->left, res);
        int right = depth(root->right, res);
        // root作为路径的根结点
        res = max(res, root->val + left + right);
        // root作为路径中的一个结点
        return max(0, root->val + max(left, right));
    }
};
