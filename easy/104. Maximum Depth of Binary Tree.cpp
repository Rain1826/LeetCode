/*Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

/*
思路：层次遍历求总层数
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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 0;
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
            depth ++;
        }
        return depth;
    }
};
