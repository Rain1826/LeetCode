/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.*/

/*
思路：递归根节点的左右子树
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
    bool help(TreeNode* node1, TreeNode* node2) {
        if(node1 == NULL && node2 == NULL) return true;
        if(node1 == NULL || node2 == NULL) return false;
        if(node1->val != node2->val) return false;
        return help(node1->left, node2->right) && help(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return help(root->left, root->right);
    }
};
