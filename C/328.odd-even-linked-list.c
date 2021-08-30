/*
 * @lc app=leetcode id=328 lang=c
 *
 * [328] Odd Even Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if( !head ) return NULL;

    struct ListNode *p_odd = head;
    struct ListNode *p_even = head->next;
    struct ListNode *p_even_head = p_even;

    while( p_odd->next && p_even->next ) {
        p_odd->next = p_even->next;
        p_odd = p_odd->next;
        p_even->next = p_odd->next;
        p_even = p_even->next;
    }

    p_odd->next = p_even_head;

    return head;
}
// @lc code=end

