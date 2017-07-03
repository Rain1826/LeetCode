/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of every node never differ by more than 1.*/

/*
思路：
判断是否是平衡二叉树首先左右子树高度相差不超过1，再判断左右子树分别是不是平衡二叉树
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
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        int height = 0;
        queue<TreeNode*> Q; 
        TreeNode* node = root;
        Q.push(node);
        while(!Q.empty()) {
            int size = Q.size();
            while(size --) {
                TreeNode* tmp = Q.front();
                Q.pop();
                if(tmp->left != NULL)
                    Q.push(tmp->left);
                if(tmp->right != NULL)
                    Q.push(tmp->right);
            }
            height ++;
        }
        return height;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return abs(height(root->left) - height(root->right)) < 2 ? isBalanced(root->left) && isBalanced(root->right) : false;
    }
};
