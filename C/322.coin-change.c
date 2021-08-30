/*
 * @lc app=leetcode id=322 lang=c
 *
 * [322] Coin Change
 */

#include <stdlib.h>
#include <string.h>

// @lc code=start

#define min( x, y ) ((x) < (y) ? (x) : (y))

int coinChange(int* coins, int coinsSize, int amount){
    int i, j;
    int *p_less_num = malloc( (amount + 1) * sizeof( int ) );

    memset( p_less_num, 1, (amount + 1) * sizeof( int ) );
    p_less_num[0] = 0;

    for( i = 1; i <= amount; i++ )
        for( j = 0; j < coinsSize; j++ )
            if( i >= coins[j] )
                p_less_num[i] = min( p_less_num[i], p_less_num[i - coins[j]] + 1 );

    int n_num = p_less_num[amount] <= amount? p_less_num[amount] : -1;

    free( p_less_num );

    return n_num;
}
// @lc code=end

