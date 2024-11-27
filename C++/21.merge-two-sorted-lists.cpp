/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode *p_curr = &dummy;
        ListNode *p_curr1 = list1;
        ListNode *p_curr2 = list2;

        while (1) {
            if (!p_curr1) {
                p_curr->next = p_curr2;
                break;
            }
            if (!p_curr2) {
                p_curr->next = p_curr1;
                break;
            }

            if (p_curr1->val > p_curr2->val) {
                p_curr->next = p_curr2;
                p_curr2 = p_curr2->next;
            }
            else {
                p_curr->next = p_curr1;
                p_curr1 = p_curr1->next;
            }
            p_curr = p_curr->next;
        }
        return dummy.next;
    }
};
// @lc code=end

