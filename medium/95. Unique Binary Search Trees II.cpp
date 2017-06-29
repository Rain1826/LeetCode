/*Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3*/

/*
思路：
1. 每一次都在一个范围内随机选取一个结点作为根。 
2. 每选取一个结点作为根，就把树切分成左右两个子树，直至该结点左右子树为空。
具体思路是：
采取的是自底向上的求解过程。 
1. 选出根结点后应该先分别求解该根的左右子树集合，也就是根的左子树有若干种，它们组成左子树集合，根的右子树有若干种，它们组成右子树集合。 
2. 然后将左右子树相互配对，每一个左子树都与所有右子树匹配，每一个右子树都与所有的左子树匹配。然后将两个子树插在根结点上。 
3. 最后，把根结点放入链表中。
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)  return vector<TreeNode*>();
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int begin, int end) {
        vector<TreeNode*> ans;
        if(begin > end) {
            ans.push_back(NULL);
            return ans;
        }
        if(begin == end) {
            ans.push_back(new TreeNode(begin));
            return ans;
        }
        vector<TreeNode*> left, right;
        for(int i = begin;i <= end;i ++) {
            left = generateTrees(begin, i - 1);
            right = generateTrees(i + 1, end);
            
            for(TreeNode* lnode : left) {
                for(TreeNode* rnode : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
