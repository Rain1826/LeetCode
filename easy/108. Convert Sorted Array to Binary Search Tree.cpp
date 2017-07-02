/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/

/*
思路：
要求根据一个有序数组，构造出一棵高度平衡的BST。
每次找到数组的中间位置，这个便是平衡BST的根节点。根节点左边区域的中间节点便是左孩子，根节点的右边区域的中间节点便是右孩子。递归求解
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
    TreeNode* mysortedArrayToBST(vector<int>& nums,int begin, int end) {
        if(begin > end)  return NULL;
        int middle = begin + (end - begin) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = mysortedArrayToBST(nums, begin, middle - 1);
        root->right = mysortedArrayToBST(nums, middle + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())  return NULL;
        return mysortedArrayToBST(nums, 0, nums.size() - 1);
    }
};
