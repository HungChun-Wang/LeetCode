/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

#include <limits.h>

// @lc code=start


int reverse(int x){
    long long n_ans = 0.0;
    while( x ) {
        n_ans = n_ans * 10 + x % 10;
        x /= 10;
    }

    if( n_ans >= INT_MAX ) return 0;
    if( n_ans <= INT_MIN ) return 0;

    return (int)n_ans;
}
// @lc code=end

