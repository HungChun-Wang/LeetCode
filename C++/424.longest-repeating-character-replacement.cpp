/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    // sliding window + map, time O(n), space(k)
    int characterReplacement(string s, int k) {
        int l_left = 0;
        int l_right;
        int l_max_freq = 0;
        int l_max_sub = 0;
        int *p_freq;
        unordered_map<char, int> umap_alpha;

        for (l_right = 0; l_right < s.length(); l_right++) {
            p_freq = &(++umap_alpha[s[l_right]]);
            l_max_freq = max(l_max_freq, *p_freq);

            if (l_right - l_left + 1 - l_max_freq > k) {
                umap_alpha[s[l_left]]--;
                l_left++;
            }
            else
                l_max_sub = max(l_max_sub, l_right - l_left + 1);
        }
        return l_max_sub;
    }

    // // sliding window, time O(k*n), space O(1)
    // int characterReplacement(string s, int k) {
    //     int l_left, l_right;
    //     int l_cnt_replace;
    //     int l_len = s.length();
    //     int l_max_sub = 0;

    //     for (char c = 'A'; c <= 'Z'; c++) {
    //         l_left = 0;
    //         l_right = 0;
    //         l_cnt_replace = 0;

    //         while (l_right < l_len) {
    //             if (s[l_right] == c)
    //                 l_right++;
    //             else if (l_cnt_replace < k) {
    //                 l_right++;
    //                 l_cnt_replace++;
    //             }
    //             else if (s[l_left] == c)
    //                 l_left++;
    //             else {
    //                 l_left++;
    //                 l_cnt_replace--;
    //             }
                
    //             l_max_sub = max(l_max_sub, l_right - l_left);
    //         }
    //     }
    //     return l_max_sub;
    // }
};
// @lc code=end

