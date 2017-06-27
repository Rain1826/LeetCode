/*Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?*/

/*
思路：用栈实现二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        inorderTraversal(root, in);
        return in;
    }
private:
    void inorderTraversal(TreeNode* root, vector<int>& in) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(node != NULL || !s.empty()) {
            if(node != NULL) {
                s.push(node);
                node = node->left;
            }
            else {
                node = s.top(); s.pop();
                in.push_back(node->val);
                node = node->right;
            }
        }
    }
};
