/*Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.*/

/*
思路：
两个有序链表合并，两个指针分别指向两个链表向后移动，添加到一个新的链表中
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* ans = NULL;
        if(p->val < q->val) {
            ans = p;
            p = p->next;
        }
        else {
            ans = q;
            q = q->next;
        }
        ListNode* head = ans;
        while(p != NULL && q != NULL) {
            if(p->val < q->val) {
                ans->next = p;
                p = p->next;
                ans = ans->next;
            }
            else {
                ans->next = q;
                q = q->next;
                ans = ans->next;
            }
        }
        while(p != NULL) {
            ans->next = p;
            p = p->next;
            ans = ans->next;
        }
        while(q != NULL) {
            ans->next = q;
            q = q->next;
            ans = ans->next;
        }
        ans->next = NULL;
        return head;
    }
};
