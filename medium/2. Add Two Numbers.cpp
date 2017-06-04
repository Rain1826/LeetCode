/*You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8*/


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
    //负责将较长的链表剩余部分添加进来
    void AddExcess(ListNode* l,ListNode* res,int carry) {
        l->val += carry;
            while(l->val == 10) {
                res->next = new ListNode(0);
                res = res->next;
                l = l->next;
                if(!l) {
                    res->next = new ListNode(1);
                    res = res->next;
                    break;
                }
                l->val += 1;
            }
            res->next = l;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        int carry = 0;
        //从个位开始相加
        while(l1 && l2) {
            int temp = l1->val + l2->val + carry;
            carry = 0;
            if(temp > 9) {
                carry = 1;
                temp %= 10;
            }
            res->next = new ListNode(temp);
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1) {
            AddExcess(l1, res, carry);
        }else if(l2) {
            AddExcess(l2, res, carry);
        }else if(carry){    //如果两链表都到末尾但carry仍为1，则需补充一个进位1
            res->next = new ListNode(1);
        }
        return head->next;
    }
};
