/*Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.*/

/*
思路：
将前序与中序序列分别分割成左右子树两部分进行递归
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
    TreeNode* build(vector<int>& preorder, int prebegin, int preend, vector<int>& inorder, int inbegin, int inend) {
        if(preend - prebegin < 0) return NULL;
        int index = inbegin;
        while(inorder[index] != preorder[prebegin]) index ++;
        TreeNode* root = new TreeNode(preorder[prebegin]);
        root->left = build(preorder, prebegin + 1, prebegin + index - inbegin, inorder, inbegin, index - 1);
        root->right = build(preorder, prebegin + index - inbegin + 1, preend, inorder, index + 1, inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int index = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        root->left = build(preorder, 1, index, inorder, 0, index - 1);
        root->right = build(preorder, index + 1, preorder.size() - 1, inorder, index + 1, inorder.size() - 1);
        return root;
    }
};
