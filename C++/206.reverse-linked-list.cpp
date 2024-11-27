/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    // time O(n), space O(1)
    ListNode* reverseList(ListNode* head) {
        ListNode *p_next;
        ListNode *p_last = nullptr;
        ListNode *p_curr = head;

        while (p_curr) {
            p_next = p_curr->next;
            p_curr->next = p_last;
            p_last = p_curr;
            p_curr = p_next;
        }
        return p_last;
    }
};
// @lc code=end

