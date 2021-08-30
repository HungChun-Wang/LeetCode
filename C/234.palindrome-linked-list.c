/*
 * @lc app=leetcode id=234 lang=c
 *
 * [234] Palindrome Linked List
 */
#include <stddef.h>
#include <stdbool.h>

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

struct ListNode *reverse_list( struct ListNode *p_head )
{
    struct ListNode *p_next;
    struct ListNode *p_prev = NULL;
    struct ListNode *p_curr = p_head;

    while( p_curr ) {
        p_next = p_curr->next;
        p_curr->next = p_prev;
        p_prev = p_curr;
        p_curr = p_next;
    }

    return p_prev;
}

bool isPalindrome( struct ListNode* p_head )
{
    struct ListNode *p_slow = p_head;
    struct ListNode *p_fast = p_head;
    struct ListNode *p_front;
    struct ListNode *p_back;

    while( p_fast && p_fast->next ) {
        p_slow = p_slow->next;
        p_fast = p_fast->next->next;
    }

    p_front = p_head;
    p_back = reverse_list( p_slow );

    while( p_back ) {
        if( p_front->val != p_back->val )
            return false;
        
        p_front = p_front->next;
        p_back = p_back->next;
    }

    return true;
}

// @lc code=end

