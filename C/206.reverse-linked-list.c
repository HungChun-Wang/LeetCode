/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */

#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p_next;
    struct ListNode *p_prev = NULL;
    struct ListNode *p_curr = head;

    while( p_curr ) {
        p_next = p_curr->next;
        p_curr->next = p_prev;
        p_prev = p_curr;
        p_curr = p_next;
    }

    return p_prev;
}
// @lc code=end

