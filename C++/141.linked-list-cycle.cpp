/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

#include <unordered_map>

// @lc code=start
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
    // // unordered map, time O(n), space(n)
    // bool hasCycle(ListNode *head) {
    //     unordered_map<ListNode*, bool> umap;
    //     ListNode *p_curr = head;

    //     while (p_curr) {
    //         if (umap[p_curr])
    //             return true;
    //         umap[p_curr] = true;
    //         p_curr = p_curr->next;
    //     }
    //     return false;
    // }

    // fast pointer, time O(n), space(1)
    bool hasCycle(ListNode *head) {
        ListNode *p_slow = head;
        ListNode *p_fast = head;

        while (p_fast && p_fast->next) {
            p_slow = p_slow->next;
            p_fast = p_fast->next->next;

            if (p_slow == p_fast)
                return true;
        }
        return false;
    }
};
// @lc code=end

