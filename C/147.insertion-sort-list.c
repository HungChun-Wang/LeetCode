/*
 * @lc app=leetcode id=147 lang=c
 *
 * [147] Insertion Sort List
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

struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode buffer;
    struct ListNode *p_curr = head;
    struct ListNode *p_next;
    struct ListNode *p_insert;

    buffer.val = 0;
    buffer.next = NULL;

    while( p_curr ) {
        p_insert = &buffer;
        
        while( p_insert->next && p_insert->next->val < p_curr->val )
            p_insert = p_insert->next;
        
        p_next = p_curr->next;
        p_curr->next = p_insert->next;
        p_insert->next = p_curr;
        p_curr = p_next;
    }

    return buffer.next;
}
// @lc code=end

int main( void )
{
    struct ListNode p1, p2, p3, p4;
    p1.val = 4;
    p2.val = 2;
    p3.val = 1;
    p4.val = 3;
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = NULL;

    insertionSortList( &p1 );
}