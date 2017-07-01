/*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]*/

/*
思路：
通过队列实现层次遍历，leftToright标志位判断是从左到右还是从右到左，从而决定index的取值
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> Queue;
        bool leftToright = true;
        Queue.push(root);
        while(!Queue.empty()) {
            int size = Queue.size();
            vector<int> tmp(size);
            int index = leftToright ? 0 : size - 1;
            while(size--) {
                TreeNode* node = Queue.front();
                tmp[index] = node->val;
                Queue.pop();
                if(node->left != NULL)
                    Queue.push(node->left);
                if(node->right != NULL)
                    Queue.push(node->right);
                index = leftToright ? index + 1 : index - 1;
            }
            leftToright = !leftToright;
            ans.push_back(tmp);
        }
        return ans;
    }
};
