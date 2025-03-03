/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    // gready
    // time O(l), l = length of string
    // space O(1)
    bool checkRecord(string s) {
        int cnt_seq_late = 0;
        int cnt_absent = 0;

        for (auto c : s) {
            if (c == 'L') {
                if (++cnt_seq_late >= 3)
                    return false;
            }
            else {
                cnt_seq_late = 0;
                if (c == 'A')
                    if (++cnt_absent >= 2)
                        return false;
            }
        }
        return true;
    }
};
// @lc code=end

