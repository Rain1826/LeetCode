/*Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.*/

/*
思路：
通过快慢指针找到中间节点进行递归
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL)	return new TreeNode(head->val);
        ListNode* node = new ListNode(0);
        node->next = head;
        ListNode* pre = node;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast) {
            pre = pre->next;
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        pre->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
