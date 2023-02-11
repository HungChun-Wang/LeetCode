/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
        int n_carry = 0;
        ListNode dummy_head;
        ListNode *p_new_node;
        ListNode *p_tail = &dummy_head;
        
        while(l1 || l2 || n_carry) {
            p_new_node = new ListNode();
            
            if(l1) {
                p_new_node->val += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                p_new_node->val += l2->val;
                l2 = l2->next;
            }
            if(n_carry)
                p_new_node->val += n_carry;
            
            if(p_new_node->val >= 10) {
                n_carry = p_new_node->val / 10;
                p_new_node->val %= 10;
            }
            else {
                n_carry = 0;
            }

            p_tail->next = p_new_node;
            p_tail = p_tail->next;
        }

        return dummy_head.next;
    }
};
// @lc code=end

