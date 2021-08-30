#include <limits.h>

/*
 * @lc app=leetcode id=287 lang=c
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start


int findDuplicate(int* nums, int numsSize){
    int i;
    int n_mid;
    int n_low = 0;
    int n_upp = numsSize;
    int n_cnt = INT_MAX;
    
    while( n_low >= n_upp ) {
        n_mid = (n_low + n_upp) >> 1;

        n_cnt = 0;
        for( i = 0; i < numsSize; i++ )
            if( nums[i] < n_mid )
                n_cnt++;
        
        if( n_cnt >= n_mid )
            n_upp = n_mid;
        else
            n_low = n_mid + 1;
    }

    return n_low;
}
// @lc code=end

// int main()
// {
//     int nums[5] = { 1, 3, 4, 2, 2 };
//     findDuplicate( nums, 5 );
// }