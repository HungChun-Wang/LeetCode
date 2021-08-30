/*
 * @lc app=leetcode id=120 lang=c
 *
 * [120] Triangle
 */

// @lc code=start


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int i, j;
    for( i = triangleSize - 2; i >= 0; i-- )
        for( j = 0; j < triangleColSize[i]; j++ )
            triangle[i][j] += triangle[i+1][j] < triangle[i+1][j+1] ? triangle[i+1][j] : triangle[i+1][j+1];
    return triangle[0][0];
}
// @lc code=end

