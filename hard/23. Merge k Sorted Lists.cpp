/*Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.*/

/*
思路：
将MergeK转换成MergeTwo，进行k-1次合并
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* ans = NULL;
        if(p->val < q->val)
        {
            ans = p;
            p = p->next;
        }
        else
        {
            ans = q;
            q = q->next;
        }
        ListNode* head = ans;
        while(p != NULL && q != NULL)
        {
            if(p->val < q->val)
            {
                ans->next = p;
                p = p->next;
                ans = ans->next;
            }
            else
            {
                ans->next = q;
                q = q->next;
                ans = ans->next;
            }
        }
        while(p != NULL)
        {
            ans->next = p;
            p = p->next;
            ans = ans->next;
        }
        while(q != NULL)
        {
            ans->next = q;
            q = q->next;
            ans = ans->next;
        }
        ans->next = NULL;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0) {
            return NULL;
        }
        for(int i = 0;i < lists.size() - 1; ++ i) {
            lists[i + 1] = mergeTwoLists(lists[i], lists[i + 1]);
        }
        return lists[lists.size() - 1];
    }
};
