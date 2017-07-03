/*Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.*/

/*
思路：
将中序与后序序列分别分割成左右子树两部分进行递归
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
    TreeNode* build(vector<int>& postorder, int postbegin, int postend, vector<int>& inorder, int inbegin, int inend) {
        if(postend - postbegin < 0) return NULL;
        int index = inbegin;
        while(inorder[index] != postorder[postend]) index ++;
        TreeNode* root = new TreeNode(postorder[postend]);
        root->left = build(postorder, postbegin, postbegin + index - inbegin - 1, inorder, inbegin, index - 1);
        root->right = build(postorder, postbegin + index - inbegin, postend - 1, inorder, index + 1, inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        int size = postorder.size();
        TreeNode* root = new TreeNode(postorder[size - 1]);
        int index = find(inorder.begin(), inorder.end(), postorder[size - 1]) - inorder.begin();
        root->left = build(postorder, 0, index - 1, inorder, 0, index - 1);
        root->right = build(postorder, index, postorder.size() - 2, inorder, index + 1, inorder.size() - 1);
        return root;
    }
};
