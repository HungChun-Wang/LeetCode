/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    // time O(n), space O(1)
    // 1. cut half
    // 2. reverse right part
    // 3. zip merge
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode *p_curr_l = head;
        ListNode *p_curr_r = head;
        ListNode *p_last;
        ListNode *p_next;
        ListNode *p_curr;
        ListNode dummy;

        // find middle node
        while (p_curr_r->next && p_curr_r->next->next) {
            p_curr_l = p_curr_l->next;
            p_curr_r = p_curr_r->next->next;
        }

        // cut half
        p_curr_r = p_curr_l->next;
        p_curr_l->next = nullptr;

        // reverse right list
        p_last = p_curr_r;
        p_curr_r = p_curr_r->next;
        p_last->next = nullptr;
        while (p_curr_r) {
            p_next = p_curr_r->next;
            p_curr_r->next = p_last;
            p_last = p_curr_r;
            p_curr_r = p_next;
        }

        p_curr_l = head;
        p_curr_r = p_last;

        // zip merge
        p_curr = &dummy;
        while (p_curr_l || p_curr_r) {
            if (p_curr_l) {
                p_curr->next = p_curr_l;
                p_curr = p_curr->next;
                p_curr_l = p_curr_l->next;
            }
            if (p_curr_r) {
                p_curr->next = p_curr_r;
                p_curr = p_curr->next;
                p_curr_r = p_curr_r->next;
            }
        }
    }
};
// @lc code=end

