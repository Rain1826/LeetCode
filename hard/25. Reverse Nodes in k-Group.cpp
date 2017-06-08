/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5*/

/*
思路：
将k个结点压栈，逆序，再添加回来
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k < 2) {
            return head;
        }
        stack<ListNode* > Stack;
        ListNode* pHead = head;
        ListNode* pTail = head;
        ListNode* pNode = head;
        bool flag = true;
        while(pNode != NULL) {
            //将k个结点压入栈中
            for(int i = 0;i < k && pNode != NULL; ++ i) {
                Stack.push(pNode);
                pNode = pNode->next;
            }
            //如果压入栈中的结点数小于k
            if(Stack.size() < k) {
                if(flag) { //表示链表总结点数小于k，直接返回head
                    return head;
                }
                while(Stack.size() > 1) {
                    Stack.pop();
                }
                pTail->next = Stack.top();
                return pHead;
            }
            if(flag) {
                pHead = Stack.top();
                pTail = Stack.top();
                flag = false;
            }
            while(!Stack.empty()) {
                pTail->next = Stack.top();
                Stack.pop();
                pTail = pTail->next;
            }
        }
        pTail->next = NULL;
        return pHead;
    }
};
