/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    // time O(n), space(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode dummy;
        ListNode* p_node_fast = &dummy;
        ListNode* p_node_slow = &dummy;
        dummy.next = head;

        for (int idx = 0; idx <= n; idx++)
            p_node_fast = p_node_fast->next;
        
        while(p_node_fast) {
            p_node_fast = p_node_fast->next;
            p_node_slow = p_node_slow->next;
        }

        p_node_slow->next = p_node_slow->next->next;
        return dummy.next;
    }
};
// @lc code=end

