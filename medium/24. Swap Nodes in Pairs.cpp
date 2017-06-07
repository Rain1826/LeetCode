/*Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.*/

/*
思路：
创建一个helper结点来帮助保存头结点，指针操作，注意细节
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* helper = new ListNode(0);
        helper->next = head;
        ListNode* cur = head;
        ListNode* pre = helper;
        while(cur != NULL && cur->next != NULL) {
            ListNode* next = cur->next->next;
            cur->next->next = cur;
            pre->next = cur->next;
            cur->next = next;
            if(next != NULL && next->next != NULL) {
                cur->next = next->next;
            }
            else break;
            pre = cur;
            cur = next;
        }
        return helper->next;
    }
};
