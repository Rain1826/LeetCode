/*Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?*/

/*
思路：首先中序遍历得到vector，在vector中找到要交换的两个元素
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
    void recoverTree(TreeNode* root) {
    	if(root == NULL)	return;
        vector<TreeNode*> inOrder;
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
                inOrder.push_back(node);
                pre = node->val;
                node = node->right;
            }
        }
        int first = 0, second = inOrder.size() - 1;
        while(first < inOrder.size() - 1 && inOrder[first]->val < inOrder[first + 1]->val) first ++;
        while(second > 0 && inOrder[second]->val > inOrder[second - 1]->val) second --;
        swap(inOrder[first]->val, inOrder[second]->val);
    }
};
