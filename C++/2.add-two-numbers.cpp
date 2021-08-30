/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n_sum;
        int n_carry = 0;
        ListNode head;
        ListNode *p_tail = &head;
        ListNode *p_new;

        while( l1 || l2 || n_carry ) {
            p_new = new ListNode(0);

            if( l1 ) {
                p_new->val += l1->val;
                l1 = l1->next;
            }
            if( l2 ) {
                p_new->val += l2->val;
                l2 = l2->next;
            }
            if( n_carry )
                p_new->val += n_carry;

            if( p_new->val >= 10 ) {
                n_carry = p_new->val / 10;
                p_new->val %= 10;
            }
            else
                n_carry = 0;

            p_tail->next = p_new;
            p_tail = p_new;
        }

        return head.next;
    }
};
// @lc code=end

