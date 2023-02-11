/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    // brute force
    int lengthOfLongestSubstring(string s) {
        int n_valid;
        int n_length;
        int n_max_length = 0;
        int n_left, n_right, i;
        unordered_map<int, int> umap;

        for(n_left = 0; n_left < s.length(); n_left++) {
            for(n_right = n_left; n_right < s.length(); n_right++) {
                n_valid = 1;

                for(i = n_left; i <= n_right; i++) {
                    if(umap[s[i]] >= 1) {
                        n_valid = 0;
                        break;
                    }
                    umap[s[i]]++;
                }

                if(n_valid) {
                    n_length = n_right - n_left + 1;
                    if (n_length > n_max_length)
                        n_max_length = n_length;
                }
                umap.clear();
            }
        }
        return n_max_length;
    }

    // slide window(hash table)
    int lengthOfLongestSubstring(string s) {
        int n_idx;
        int n_length;
        int n_left = 0;
        int n_max_length = 0;

        // key: char
        // value: index
        unordered_map<int, int> umap;

        for(int n_right = 0; n_right < s.length(); n_right++) {
            n_idx = umap[s[n_right]];

            // right value repeat, assign record value to left index
            if(n_idx > n_left) {
                n_left = n_idx;
            }

            // record max length
            n_length = n_right - n_left + 1;
            if (n_max_length < n_length)
                n_max_length = n_length;

            // record right index + 1
            umap[s[n_right]] = n_right + 1;
        }

        return n_max_length;
    }

    // slide window(array)
    int lengthOfLongestSubstring(string s) {
        int n_idx;
        int n_length;
        int n_left = 0;
        int n_max_length = 0;

        vector<int> vec(128, 0);

        for(int n_right = 0; n_right < s.length(); n_right++) {
            n_idx = vec[s[n_right]];

            // right value repeat, assign record value to left index
            if(n_left < n_idx) {
                n_left = n_idx;
            }

            // record max length
            n_length = n_right - n_left + 1;
            if (n_max_length < n_length)
                n_max_length = n_length;

            // record right index + 1
            vec[s[n_right]] = n_right + 1;
        }

        return n_max_length;
    }
};
// @lc code=end

