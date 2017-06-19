/*Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.*/

/*
思路：
链表的旋转，先遍历得到整个链表长度，并将首尾指针相连成为一个环，再将尾指针向后移动 length - k 位，更新头结点和尾结点
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)    return NULL;
        ListNode* newHead = head;
        ListNode* tail = head;
        int length = 1;
        while(tail->next) {
            tail = tail->next;
            length ++;
        }
        tail->next = head;
        k %= length;
        for(int i = 0;i < length - k;i ++) {
            tail = tail->next;
        }
        newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }
};
