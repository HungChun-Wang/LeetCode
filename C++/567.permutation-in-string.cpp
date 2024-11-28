/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // sliding window + vector, time O(n), space O(k)
    bool checkInclusion(string s1, string s2) {
        int l_left;
        int l_right;
        int is_meet;
        int l_len_s1 = s1.size();
        int l_len_s2 = s2.size();
        vector<char> vec_freq(26, 0);

        // add alphabat freq of s1 to vector
        for (l_left = 0; l_left < l_len_s1; l_left++)
            vec_freq[s1[l_left] - 'a']++;

        l_left = 0;
        l_right = 0;
        while (l_right < l_len_s2) {
            vec_freq[s2[l_right] - 'a']--;

            if (l_right - l_left + 1 > l_len_s1) {
                vec_freq[s2[l_left] - 'a']++;
                l_left++;
            }

            // check if vector is all zero
            is_meet = true;
            for (auto l_freq : vec_freq) {
                if (l_freq != 0) {
                    is_meet = false;
                    break;
                }
            }

            if (is_meet)
                return true;

            l_right++;
        }
        return false;
    }
};
// @lc code=end
