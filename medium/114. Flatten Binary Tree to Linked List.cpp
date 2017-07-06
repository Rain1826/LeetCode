/*Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.*/

/*
思路：
根据提示中的信息，递归实现
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
    void help(TreeNode* root) {
        if(root == NULL) return;
        if(root->left == NULL) {
            help(root->right);
            return;
        }
        TreeNode* lnode = root->left;
        help(root->left);
        root->left = NULL;
        TreeNode* rnode = root->right;
        root->right = lnode;
        while(lnode->right != NULL) lnode = lnode->right;
        lnode->right = rnode;
        help(rnode);
    }
    void flatten(TreeNode* root) {
        help(root);
    }
};
