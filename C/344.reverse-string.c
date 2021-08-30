/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */

// @lc code=start


void reverseString(char* s, int sSize){
    char temp;
    int n_left = 0;
    int n_right = sSize - 1;

    while( n_left < n_right ) {
        temp = s[n_left];
        s[n_left++] = s[n_right];
        s[n_right--] = temp;
    }
}
// @lc code=end

