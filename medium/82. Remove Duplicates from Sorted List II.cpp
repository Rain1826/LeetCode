/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.*/

/*
思路：递归
分两种情况，需要更换头结点和不需更换头结点
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* pre = head;
        ListNode* cur = head->next;
        if(pre->val == cur->val) {
            while(cur != NULL && cur->val == pre->val) {
                cur = cur->next;
            }
            return deleteDuplicates(cur);
        }
        else {
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};
