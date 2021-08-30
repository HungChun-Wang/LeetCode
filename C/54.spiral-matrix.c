/*
 * @lc app=leetcode id=54 lang=c
 *
 * [54] Spiral Matrix
 */

#include <stddef.h>

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if( matrixSize == 0) return NULL;
    
    *returnSize = matrixSize * matrixColSize[0];
    int n_idx = 0;
    int n_dir = 0;
    int n_row = 0;
    int n_col = 0;
    int n_bound_up = 0;
    int n_bound_down = matrixSize - 1;
    int n_bound_left = 0;
    int n_bound_right = matrixColSize[0] - 1;
    int *p_ans = malloc( *returnSize * sizeof( int ) );

    for( int i = 0; i < *returnSize; i++ ) {
        p_ans[n_idx++] = matrix[n_row][n_col];

        switch( n_dir ) {
        case 0:
            if( n_col == n_bound_right ) {
                n_dir = 1;
                n_bound_up++;
                n_row++;
            }
            else
                n_col++;
            break;
        case 1:
            if( n_row == n_bound_down ) {
                n_dir = 2;
                n_bound_right--;
                n_col--;
            }
            else
                n_row++;
            break;
        case 2:
            if( n_col == n_bound_left ) {
                n_dir = 3;
                n_bound_down--;
                n_row--;
            }
            else
                n_col--;
            break;
        case 3:
            if( n_row == n_bound_up ) {
                n_dir = 0;
                n_bound_left++;
                n_col++;
            }
            else
                n_row--;
            break;
        }
    }

    return p_ans;
}
// @lc code=end

