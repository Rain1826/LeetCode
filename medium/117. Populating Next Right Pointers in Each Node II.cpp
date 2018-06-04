/*Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL*/

/*
思路：
通过三个指针，包括父级结点、下一级的头结点和尾结点，来对next指针进行赋值
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *now, *head, *tail;
        now = root;
        head = tail = NULL;
        while(now) {
            if(now->left) {
                if(tail) tail = tail->next = now->left;
                else head = tail = now->left;
            }
            if(now->right) {
                if(tail) tail = tail->next = now->right;
                else head = tail = now->right;
            }
            if(!(now = now->next)) {
                now = head;
                head = tail = NULL;
            }
        }
    }
};
