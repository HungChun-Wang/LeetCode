/*
 * @lc app=leetcode id=24 lang=c
 *
 * [24] Swap Nodes in Pairs
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


struct ListNode* swapPairs(struct ListNode* head){
    if( head == NULL ) return NULL;
    if( head->next == NULL ) return head;

    struct ListNode buffer;
    buffer.next = head;
    struct ListNode *p_prev = &buffer;
    struct ListNode *p_curr = head;

    while( p_curr && p_curr->next ) {
        p_prev->next = p_curr->next;
        p_prev = p_curr;
        p_curr = p_curr->next;
        p_prev->next = p_curr->next;
        p_curr->next = p_prev;
        p_curr = p_prev->next;
    }

    return buffer.next;
}
// @lc code=end

