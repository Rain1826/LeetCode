/*Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.*/

/*
思路：
得到中序遍历序列，判断该序列是否是严格递增的
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
    bool isValidBST(TreeNode* root) {
        if(root == NULL)	return true;
        vector<int> inOrder;
        stack<TreeNode*> S;
        TreeNode* node = root;
        int pre = INT_MIN;
        while(node != NULL || !S.empty()) {
            if(node != NULL) {
                S.push(node);
                node = node->left;
            }
            else {
                node = S.top();	S.pop();
                inOrder.push_back(node->val);
               	if(inOrder.size() > 1 && inOrder.back() <= pre) {
                    return false;
                }
                pre = node->val;
                node = node->right;
            }
        }
        return true;
    }
};
