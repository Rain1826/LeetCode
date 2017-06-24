/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.*/

/*
思路：
遇到重复结点就后移，并与pre结点相连
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
        while(cur != NULL) {
            while(cur != NULL && cur->val == pre->val) {
                cur = cur->next;
            }
            pre->next = cur;
            pre = pre->next;
            if(cur != NULL) {
                cur = cur->next;
            }
        }
        return head;
    }
};
