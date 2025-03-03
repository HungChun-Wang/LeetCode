/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // greedy
    // time O(n)
    // space O(1)
    bool detectCapitalUse(string word) {
        int len = word.size();
        if (len <= 1) return true;

        bool isCap1st = isupper(word[0]);
        bool isCap2nd = isupper(word[1]);

        if (!isCap1st && isCap2nd)
            return false;

        bool isNeedCap = isCap1st && isCap2nd;
        bool isCapCur;

        for (int i = 2; i < len; i++) {
            isCapCur = isupper(word[i]);
            if (isNeedCap && !isCapCur)
                return false;
            else if (!isNeedCap && isCapCur)
                return false;
        }
        return true;
    }
};
// @lc code=end

