/*Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.*/

/*
思路：
关键思路是用pre，begin，then三个指针实现链表的部分反转功能
处理顺序是begin.next --- then.next --- pre.next，即从后向前处理
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* node = new ListNode(0);
        node->next = head;
        ListNode* pre = node;
        for(int i = 0;i < m - 1;i ++) {
            pre = pre->next;
        }
        ListNode* begin = pre->next;
        ListNode* then = begin->next;
        //交换n - m次
        for(int i = 0;i < n - m;i ++) {
            begin->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = begin->next; 
        }
        return node->next;
    }
};
