/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <string.h>

// @lc code=start


int lengthOfLongestSubstring(char * s){
    int i = 0;
    int n_start = -1;
    int n_ans = 0;
    int table[127];
    memset( table, -1, 127 * sizeof( int ) );

    while( s[i] != '\0' ) {
        if( table[s[i]] > n_start )
            n_start = table[s[i]];
        table[s[i]] = i;

        if( n_ans < i - n_start )
            n_ans = i - n_start;
        i++;
    }
    return n_ans;
}
// @lc code=end

