/*
 * @lc app=leetcode id=88 lang=c
 *
 * [88] Merge Sorted Array
 */

// @lc code=start


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int n_idx = m + n - 1;

    m--;
    n--;
    while( n_idx >= 0 ) {
        if( m >= 0 ) {
            if( n >= 0 && nums1[m] > nums2[n] || n < 0 )
                nums1[n_idx--] = nums1[m--];
            else
                nums1[n_idx--] = nums2[n--];
        }
        else
            nums1[n_idx--] = nums2[n--];
    }
}
// @lc code=end

