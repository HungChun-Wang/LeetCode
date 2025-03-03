/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    // time O(n)
    // space O(1)
    bool judgeCircle(string moves) {
        int vertical = 0;
        int horizontal = 0;

        for (auto move : moves) {
            switch (move) {
            case 'U':
                vertical++;
                break;
            case 'D':
                vertical--;
                break;
            case 'R':
                horizontal++;
                break;
            case 'L':
                horizontal--;
                break;
            }
        }
        return !vertical && !horizontal;
    }
};
// @lc code=end

