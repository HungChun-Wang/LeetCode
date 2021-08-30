/*
 * @lc app=leetcode id=541 lang=c
 *
 * [541] Reverse String II
 */

// @lc code=start


char * reverseStr(char * s, int k){
    if( !s ) return s;

    char temp;
    int n_start;
    int n_left;
    int n_right;
    int n_len = 0;

    while( s[n_len] != '\0' )
        n_len++;
    
    for( n_start = 0; n_start < n_len; n_start += 2 * k ) {
        n_left = n_start;
        n_right = n_left + k > n_len ? n_len - 1 : n_left + k - 1;

        while( n_left < n_right ) {
            temp = s[n_left];
            s[n_left] = s[n_right];
            s[n_right] = temp;
            n_left++;
            n_right--;
        }
    }

    return s;
}
// @lc code=end

