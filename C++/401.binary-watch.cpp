/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    // time O(12 * 60)
    // space O(1), except output
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> vec_rst;
        string temp;

        for (int hour = 0; hour < 12; hour++) {
            for (int min = 0; min < 60; min++) {
                if (__builtin_popcount(hour) + __builtin_popcount(min) == turnedOn) {
                    temp = to_string(hour);
                    temp += ":";
                    if (min < 10) temp += "0";
                    temp += to_string(min);
                    vec_rst.push_back(temp);
                }
            }
        }
        return vec_rst;
    }
};
// @lc code=end

