/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

#include <stdbool.h>

// @lc code=start


bool isPalindrome_(int x){
    if( x < 0 || ( x >= 10 && x % 10 == 0) ) return false;

    int n_rev = 0;
    
    while( n_rev < x ) {
        n_rev = n_rev * 10 + x % 10;
        x /= 10;
    }

    return x == n_rev | x == n_rev / 10;
}
// @lc code=end

