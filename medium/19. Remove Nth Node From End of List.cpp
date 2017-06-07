/*Given a linked list, remove the nth node from the end of list and return its head.

For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.
   
Note:
Given n will always be valid.
Try to do this in one pass.*/

/*
思路：
通过前后两个指针中间相隔n-1，当后指针移动到末尾时，前面一个指针就是要删除的结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = NULL;
        ListNode* front = head;
        ListNode* back = head;
        for(int i = 0;i < n - 1; ++ i) {
            back = back->next;
        }
        while(back->next != NULL) {
            pre = front;
            back = back->next;
            front = front->next;
        }
        if(pre == NULL) {
            return head->next;
        }
        pre->next = front->next;
        return head;
    }
};
