/*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]*/

/*
思路：
队列实现层次遍历，在插入时每次在头部插入
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> Queue;
        Queue.push(root);
        while(!Queue.empty()) {
            vector<int> tmp;
            int size = Queue.size();
            while(size--) {
                TreeNode* node = Queue.front();
                tmp.push_back(node->val);
                Queue.pop();
                if(node->left != NULL)
                    Queue.push(node->left);
                if(node->right != NULL)
                    Queue.push(node->right);
            }
            ans.insert(ans.begin(), tmp);
        }
        return ans;
    }
};
