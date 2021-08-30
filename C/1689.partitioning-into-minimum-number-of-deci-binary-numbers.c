/*
 * @lc app=leetcode id=1689 lang=c
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

#include <stddef.h>

// @lc code=start


int minPartitions(char * n){
    if( n == NULL ) return 0;
    
    int i = 0;
    char n_max = 0;

    while( n[i] != '\0' ) {
        if( n_max < n[i] )
            n_max = n[i];
        i++;
    }

    return n_max - '0';
}
// @lc code=end

