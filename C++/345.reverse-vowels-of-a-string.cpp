/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int len_str = s.size();
        int il = 0;
        int ir = len_str - 1;

        while (1) {
            while(il < len_str && !isVowel(s[il])) il++;
            while(ir >= 0 && !isVowel(s[ir])) ir--;
            
            if (il < ir)
                swap(s[il++], s[ir--]);
            else
                break;
        }
        return s;
    }

    inline bool isVowel(char c) {
        return c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u';
    }
};
// @lc code=end

